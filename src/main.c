#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <limits.h>
#include <ctype.h>

#define NLSH_VERSION "1.0.0"
#define INPUT_SIZE 4096

char prompt[INPUT_SIZE] = "";
char shell_type[16] = "bash";
char character[128] = "~";
int locate_archives = 0;
char current_directory[PATH_MAX];

void load_config(void) {
    const char *home = getenv("HOME");
    if (!home) return;

    prompt[0] = '\0';
    strcpy(character, "~");
    locate_archives = 0;
    strcpy(shell_type, "bash");

    char path[PATH_MAX];
    snprintf(path, sizeof(path), "%s/.nlshrc", home);

    FILE *file = fopen(path, "r");
    if (!file) return;

    char line[INPUT_SIZE];

    while (fgets(line, sizeof(line), file)) {
        if (strncmp(line, "CHARACTER", 9) == 0) {
            char *s = strchr(line, '"');
            char *e = s ? strchr(s + 1, '"') : NULL;
            if (s && e) {
                *e = '\0';
                snprintf(character, sizeof(character), "%s", s + 1);
            }
            continue;
        }

        if (strstr(line, "NLSH__LOCATE__ARCHIVES")) {
            locate_archives = strstr(line, "true") != NULL;
            continue;
        }

        if (strncmp(line, "NLSH__SHELL", 11) == 0) {
            char *s = strchr(line, '"');
            char *e = s ? strchr(s + 1, '"') : NULL;
            if (s && e) {
                *e = '\0';
                if (strcmp(s + 1, "zsh") == 0 ||
                    strcmp(s + 1, "bash") == 0)
                    snprintf(shell_type, sizeof(shell_type), "%s", s + 1);
            }
            continue;
        }

        if (strncmp(line, "PROMPT", 6) == 0) {
            char *s = strchr(line, '\'');
            char *e = strrchr(line, '\'');
            if (s && e && s != e) {
                s++;
                *e = '\0';
                snprintf(prompt, sizeof(prompt), "%s", s);
            }
        }
    }

    fclose(file);
}
int valid_hex(const char *color) {
    if (strlen(color) != 6)
        return 0;

    for (int i = 0; i < 6; i++) {
        if (!isxdigit((unsigned char)color[i]))
            return 0;
    }

    return 1;
}

void print_prompt(void) {
    const char *p = prompt;
    char current_directory[PATH_MAX];
    const char *home = getenv("HOME");

    if (getcwd(current_directory, sizeof(current_directory))) {
        if (home && strcmp(current_directory, home) == 0) {
            strcpy(current_directory, "~");
        }
    } else {
        snprintf(current_directory, sizeof(current_directory), "%s", character);
    }

    while (*p) {
        while (isspace((unsigned char)*p))
            p++;

        if (*p == '"')
            p++;

        if (*p != '{')
            break;

        p++;

        char color[16] = {0};
        int i = 0;

        while (*p && *p != '}' && i < 15)
            color[i++] = *p++;

        if (*p != '}')
            break;

        p++;

        while (isspace((unsigned char)*p))
            p++;

        if (*p != '=')
            break;

        p++;

        while (isspace((unsigned char)*p))
            p++;

        if (*p != '"')
            break;

        p++;

        if (strcmp(color, "normal") == 0) {
            printf("\033[0m");
        }
        else if (color[0] == '#' && valid_hex(color + 1)) {
            int r, g, b;

            sscanf(color + 1, "%2x%2x%2x", &r, &g, &b);

            printf("\033[38;2;%d;%d;%dm", r, g, b);
        }
        else {
            break;
        }

        while (*p && *p != '"') {
            size_t len = strlen(character);

            if (locate_archives && len > 0 &&
                strncmp(p, character, len) == 0) {
                printf("%s", current_directory);
                p += len;
            } else {
                putchar(*p++);
            }
        }

        printf("\033[0m");

        if (*p == '"')
            p++;
    }

    fflush(stdout);
}

void execute_command(char *input) {
    pid_t pid = fork();

    if (pid < 0) {
        perror("nlsh-shell");
        return;
    }

    if (pid == 0) {
        execlp(shell_type, shell_type, "-c", input, (char *)NULL);
        perror("nlsh-shell");
        exit(127);
    }

    int status;
    waitpid(pid, &status, 0);
}

int main(void) {
    char input[INPUT_SIZE];

    load_config();

    printf("nlsh-shell %s\n", NLSH_VERSION);

    while (1) {
        print_prompt();

        if (!fgets(input, sizeof(input), stdin))
            break;

        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, "exit") == 0)
            break;

         if (strcmp(input, "restart-shell") == 0) {
    if (prompt[0] != '\0') {
        prompt[0] = '\0';
        load_config();
    }
    continue;
}

        if (strlen(input) == 0)
            continue;

        if (strncmp(input, "cd", 2) == 0 && (input[2] == 0 || isspace((unsigned char)input[2]))) {
            char *dir = input + 2;
            while (isspace((unsigned char)*dir)) dir++;
            if (*dir == 0) dir = getenv("HOME");
            if (dir && chdir(dir) != 0) perror("cd");
            continue;
        }
        execute_command(input);
    }

    return 0;
}
