<div align="center">

# <img src="https://github.com/Grihladin/42-project-badges/blob/main/badges/pipexe.png" width="150" height="150"> 

</div>

Pipex([42Heilbronn](https://www.42heilbronn.de/en/) project) recreates the behavior of shell pipes in C. The program executes two commands in sequence, using pipes to redirect the output of the first command as input to the second command.

## 🛠️ Implementation

- **Process Management**: Uses `fork()` to create child processes for each command
- **Pipe Communication**: Creates pipes to connect stdout of first command to stdin of second
- **File Redirection**: Handles input/output file redirection using `dup2()`
- **Path Resolution**: Searches for executables in PATH environment variable
- **Error Handling**: Comprehensive error checking for all system calls
- **Submodule Integration**: Uses external libft and ft_printf libraries as git submodules
- **Memory Management**: Proper cleanup of allocated memory and file descriptors

**Shell equivalent:**
```bash
< file1 cmd1 | cmd2 > file2
```

**Pipex equivalent:**
```bash
./pipex file1 cmd1 cmd2 file2
```

## 📦 Installation

**Requirements:**
- macOS or Linux
- Make

```bash
git clone https://github.com/Grihladin/42HN-pipex.git
cd 42HN-pipex
make
```

## 🚀 Usage

```bash
./pipex infile cmd1 cmd2 outfile
```

**Parameters:**
- `infile`: Input file to read from
- `cmd1`: First command to execute (with arguments in quotes if needed)
- `cmd2`: Second command to execute (with arguments in quotes if needed)
- `outfile`: Output file to write the final result

**Example:**

```bash
./pipex infile "grep hello" "wc -l" outfile
```

## 📁 Project Structure

```
42HN-pipex/
├── inc/
│   └── pipex.h              # Header file with structures and function declarations
├── src/
│   ├── main.c               # Main program entry point and process management
│   ├── cmd_parse_ft.c       # Command parsing and path resolution
│   └── ft.c                 # Utility functions and cleanup
├── libft/                   # Libft submodule for string functions
│   ├── inc/libft.h          # Libft header
│   └── src/                 # Libft source files
├── ft_printf/               # ft_printf submodule for formatted output
│   ├── inc/ft_printf.h      # ft_printf header
│   └── src/                 # ft_printf source files
├── Makefile                 # Build configuration with submodule support
├── .gitmodules              # Git submodule configuration
├── infile                   # Sample input file
├── outfile                  # Sample output file
└── README.md                # Project documentation
```

---

Made with ❤️ by **[mratke](https://github.com/Grihladin)** - 42 Heilbronn
