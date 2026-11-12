# NLSH — New Linux Shell

An independent command-line shell for Termux and Android.

NLSH is an independent shell project developed in C, designed to provide its own command-line environment for Termux and Android.

The project aims to offer a lightweight, customizable and extensible shell, with its own interpreter, configuration system and interactive command-line experience.

---

# About the Project

NLSH (New Linux Shell) is a shell implementation created to explore and provide an alternative command-line experience in Android environments.

Unlike a simple command wrapper, NLSH is designed around its own shell implementation and interpreter.

The project is developed in C and uses native Android system libraries.

Its architecture is intended to support future improvements, additional shell features and deeper integration with the Termux environment.

Main Features

- Independent shell implementation.
- Written in C.
- Native ARM64 support.
- Android compatibility.
- Termux environment integration.
- Custom command interpreter.
- Customizable shell configuration.
- Dedicated configuration file.
- Interactive terminal environment.
- Dynamic prompt development.
- Lightweight executable.
- Native Android library integration.
- Extensible project structure.

# Project Information

Property| Value
Project| NLSH
Full name| New Linux Shell
Package name| nlsh-shell
Current version| 1.0.0
Programming language| C
Architecture| ARM64 (aarch64)
Platform| Android
Environment| Termux
Executable| nlsh
Package format| DEB
Build system| Native compilation

Installation

Install using a local DEB package

If you already have the NLSH package:

pkg install ./nlsh-shell_1.0.0_aarch64.deb

Start NLSH

After installation, execute:

nlsh

Building from Source

Clone the repository:

git clone https://github.com/Tarzarov588/nlsh-shell.git

Enter the project directory:

cd nlsh-shell

Compile the project using the available build configuration.

The resulting executable is located in:

build/nlsh-shell

# Project Structure

nlsh-shell/
│
├── build/
│   └── nlsh-shell
│
├── package/
│   ├── DEBIAN/
│   │   └── control
│   │
│   └── data/
│       └── data/
│           └── com.termux/
│               └── files/
│                   └── usr/
│                       ├── bin/
│                       │   └── nlsh
│                       │
│                       └── share/
│                           └── nlsh-shell/
│
├── src/
│   ├── main.c
│   └── main.c.backup
│
└── README.md

Configuration

NLSH is designed to support its own configuration system.

The planned configuration file is:

~/.nlshrc

This file is intended to provide a dedicated location for shell customization and user preferences.

Technical Details

NLSH uses native Android system libraries, including:

- "libc.so"
- "libdl.so"

The current executable is an ELF 64-bit ARM aarch64 binary.

Build environment:

- Android NDK r30
- Android API 24 or newer
- ARM64 architecture

Development

NLSH is an evolving project.

Future development may include:

- Improved command interpretation.
- Advanced prompt customization.
- Environment variable management.
- Improved shell configuration.
- Command history.
- Autocompletion.
- Additional built-in commands.
- Better shell integration.
- Extended scripting capabilities.

These are development goals and are not necessarily available in version 1.0.0.

Version History

Version 1.0.0

Initial packaged release.

- Initial NLSH executable.
- ARM64 compilation.
- Termux package structure.
- DEB package generation.
- Initial command installation.

Author

Tarzarov588

GitHub:

https://github.com/Tarzarov588

License

No license has been specified yet.

All rights reserved unless a license is added to this repository.

---

NLSH — New Linux Shell

An independent shell project for Termux and Android.