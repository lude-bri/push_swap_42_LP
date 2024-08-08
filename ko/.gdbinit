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
	disp idx
	disp str_cnt
	disp *strs
	disp strs[str_cnt - 1 - idx]
	display *this
	display this
	display *this->pdata
	display this->pdata[idx]

end

define normailize_int
	disp idx
	disp *arr
	disp size
	disp *sorted_arr
	disp sorted_arr[idx]
	disp arr[idx]
end

define quick_sort
	disp left
	disp right
	disp i
	disp j
	disp pivot
	disp arr[i]
	disp arr[j]
end

define sort_ab
	disp *pab
	disp partition_size
	disp big_pivot
	disp small_pivot
end

define binary_search
	disp begin
	disp mid
	disp end
	disp arr[mid]
	disp target
end

#  Start
fs cmd
break main
run 65 45 71 6 30 51 12 50 74 92 88 5
main


