##
## Settings
#

set trace-commands on
set logging enabled on
set print pretty on
set print array on

# main.c
define main
	display argc
	display *argv@argc
	display tokens
	display *tokens
	display pab
	display *pab
end

define new_ab
	display *this
	display this
	display strs
end

#  Start
fs cmd
break main
run 65 45 71 6 30 51 12 50 74 92 88 5
record
main


