# cleandir

Cleandir is a simple file deletion program. Cleandir's intended use is to delete **ALL** files in a specified directory but can also delete directories.  

More info on the [wiki](https://github.com/O-LavenderAshburn/clean_directory/wiki).

## Usage
`cleandir <path to dir>`
## Flags

### [-f --force] Forces the deletion of files 
`cleandir -f <path to dir>`
-f differs from default behaviour by not prompting the user befor cleaning files in a directory i.e. -f will force delete all files in a directory

### [-d --destroy] Removes A directory
`cleandir -d <path to dir>`
Destroys sub-directory, files and itself 

### [-p --path] Spcify path to directory
`cleandir -p <path to dir> -f`
-p can be used in the case the path is specified before other flag arguments are uesd 

### [-h --help]
`cleandir -h`
Outputs help infromation

### [--verbose]
`cleandir --verbose <path to dir>`
Verbose output

# Future features

## File whitelisting 
Whitelist files so they are not deleted 

## Directory whitelisting 
Whitelist Directories so they are not deleted 

## File blacklisting 
blacklist files so they are deleted when -b --blacklist flag is set 

## Rexgex deletion
Delete files based on regex

## Extension deletion
Delete files based on extention 
