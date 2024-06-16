# omnTools

A custom command-line tool that can be freely extended as needed.

This tool is only available for the Windows platform, if you want to use it on Linux, go to [CmdUtils](https://github.com/lmliheng/CmdUtils).

## Deploy

Enter on the command:

```shell
git clone https://github.com/limitless-0day/omnTools.git
```

Go to the project directory and compile：

```shell
cd omnTools
cmake -B build
cmake --build build
```

If you're new to CMake or you want to avoid using commands, you can run `build.bat`.

```shell
cd omnTools
build.bat
```

## Usage

You can add the resulting executable to your computer's environment variables, which can then be easily used on the command line. Note: For ease of use, it is recommended that you change the name of the generated executable file to omn.exe.

Here are some basic usages, but if you'd like to learn more, head over: [omnTools](https://omn.agsn.site).

```shell
<<<<<<< HEAD
omn model mkdocs #Generate a MkDocs template.
=======
omn i mingw #Install mingw.
>>>>>>> 7206842962c04da07ef98d6f24454e12fe252f6e
omn tip git #Print a collection of commonly used git commands.
```
