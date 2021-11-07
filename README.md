# Pipex
Project: Pipex | 42. Reproduce **Shell** command ```<file1 cmd1 | cmd2> file2```.

Succeeded with:

[![jaeskim's 42Project Score](https://badge42.herokuapp.com/api/project/mmahias/pipex)](https://github.com/Mmahias/badge42)

--------------------------------------------------------------------------------------------------------------------------


## Usage:

It should be executed in this way:
```bash
$> ./pipex file1 cmd1 cmd2 file2
```

The execution of the pipex program should do the same as the next shell command:
```bash
$> < file1 cmd1 | cmd2 > file2
```
----------------------------------------------------------------

### Examples:

```bash
$> ./pipex infile "ls -l" "wc -l" outfile
```
should be the same as:  ```< infile ls -l | wc -l > outfile```

```bash
$> ./pipex infile "grep a1" "wc -w" outfile
```
should be the same as:  ```< infile grep a1 | wc -w > outfile```
