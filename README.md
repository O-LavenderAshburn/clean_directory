# cleandir

cleandir is a simple Linux file deletion program. cleandir deletes **ALL** files in a specified directory.

## Usage
`cleandir <path to dir>`
## Flags

### [-f --force] Forces the deletion of files 
`cleandir -f <path to dir>`
-f differs from default behaviour by not prompting the user befor cleaning files in a directory i.e. -f will force delete all files in a directory

### [-p --path] Spcify path to directory
`cleandir -p <path to dir> -f`
-p can be used in the case the path is specified before other flag arguments are uesd 

### [-h --help]
`cleandir -h`
Outputs help infromation


### [--verbose]
`cleandir --verbose <path to dir>`
Verbose output
