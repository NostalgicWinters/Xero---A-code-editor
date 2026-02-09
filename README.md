# Xero — A Code Editor

A lightweight, desktop code editor application written in C++ using Qt.
Designed for basic text editing and code development with a native look and feel.

## Features

- Cross-platform C++/Qt GUI application

- Basic code editing interface

- Menu and toolbar for file operations

- Custom menu bar styling

- Prepared UI and logic structure for expansion


## Getting Started

These instructions will help you build and run Xero on your local machine.

### Prerequisites

You will need:

- Qt (version 5 or 6 recommended)

- C++17 compatible compiler (e.g., GCC, Clang, MSVC)

- CMake build system

### Build Instructions

1) Clone the repo
```
git clone https://github.com/NostalgicWinters/Xero---A-code-editor.git
cd Xero---A-code-editor
```

2) Create build directory
```
mkdir build
cd build
```

3) Configure project with CMake
```
cmake ..
```

4) Build the executable
```
cmake --build .
```

5) Run the application
```
./Xero
```
(On Windows the executable will be Xero.exe.)

## Project Structure
```
├── CMakeLists.txt        # Build configuration
├── main.cpp              # Application entry point
├── mainwindow.h          # Main window definition
├── mainwindow.cpp        # Main window implementation
├── mainwindow.ui         # Qt UI layout file
├── CodeEditor_en_US.ts   # Translation file
├── menubarStyle.cpp      # Custom menu bar logic
├── .gitignore
```

## Dependencies

- Qt Widgets

- Qt UI forms

- CMake
(Install the Qt SDK for your platform to satisfy these dependencies.)

## How It Works

- main.cpp initializes the Qt application and shows the main window.

- mainwindow.ui defines the UI layout in Qt Designer format.

- mainwindow.cpp/.h contain the logic for UI behavior and interactions.

- menubarStyle.cpp provides customized styling for the menu bar.

- Translation file supports localization of UI strings.

## Contributing

Contributions are welcome:

1) Fork the repository.

2) Create a feature branch (git checkout -b feature/...).

3) Commit with clear messages.

4) Open a pull request.

## Acknowledgments

- Built using Qt

- Inspired by classic desktop code editors

- Thanks to contributors and community for support
