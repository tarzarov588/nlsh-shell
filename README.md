# NLSH — New Linux Shell

A configurable command-line shell for Termux and Android, written in C.

NLSH provides its own interactive interface, configuration system and command management. In version 1.0.0, command interpretation and execution are delegated to a configurable Bash or Zsh backend.

## About

NLSH is a lightweight shell project designed for Android environments, especially Termux.

It provides a dedicated interactive environment with customizable prompts and configuration options.

## Features

- Written in C.
- Interactive command-line interface.
- ARM64 (aarch64) support.
- Dedicated configuration file (`~/.nlshrc`).
- Configurable Bash or Zsh execution backend.
- Customizable prompt.
- RGB hexadecimal prompt colors.
- Built-in commands:
  - `cd`
  - `exit`
  - `restart-shell`
- Termux integration.

## Project Information

| Property | Value |
|---|---|
| Project | NLSH |
| Full name | New Linux Shell |
| Package name | nlsh-shell |
| Version | 1.0.0 |
| Programming language | C |
| Architecture | aarch64 |
| Platform | Android |
| Environment | Termux |
| Executable | nlsh |
| Package format | DEB |
| License | MIT |

## Installation

To install a locally downloaded DEB package:

```bash
```
pkg install ./nlsh-shell_1.0.0_aarch64.deb
Starting NLSH
Run:
nlsh
Configuration
NLSH uses the following configuration file:
~/.nlshrc
The configuration file supports:
CHARACTER: sets the character used by the prompt system.
NLSH__LOCATE__ARCHIVES: enables or disables the character replacement behavior.
NLSH__SHELL: selects Bash or Zsh as the execution backend.
PROMPT: defines the prompt appearance and colors.
The default execution backend is Bash.
Only Bash and Zsh are supported as execution backends in version 1.0.0.
Restarting the configuration
Use the built-in command:
restart-shell
This reloads the NLSH configuration.
Building from Source
Clone the repository:
git clone https://github.com/Tarzarov588/nlsh-shell.git
Enter the project directory:
cd nlsh-shell
Compile with Clang:
clang -Wall -Wextra -O2 src/main.c -o nlsh
Run the executable:
./nlsh
Project Structure
nlsh-shell/
├── src/
│   └── main.c
├── package/
│   ├── DEBIAN/
│   └── data/
├── build/
├── LICENSE
├── README.md
└── .gitignore
Technical Details
NLSH is implemented in C and uses native system interfaces.
In version 1.0.0, NLSH provides its own interactive interface and configuration handling, while Bash or Zsh performs command interpretation and execution.
An independent command interpreter is not yet implemented.
Future Development
Possible future improvements include:
Native command interpretation.
Environment variable management.
Command history.
Autocompletion.
Additional built-in commands.
Extended scripting capabilities.
Improved shell integration.
These are development goals and are not necessarily available in version 1.0.0.
Version History
Version 1.0.0
Initial release.
Initial NLSH executable.
ARM64 compilation.
Termux DEB package.
Interactive shell interface.
Initial configuration system.
Author
Tarzarov588
GitHub: https://github.com/Tarzarov588⁠�
License
This project is licensed under the MIT License. See the LICENSE file for details.
NLSH — New Linux Shell
