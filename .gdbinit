
set trace-commands on
set logging enabled on
set print pretty on
set print array on

# main.c
define main
	display ac
	display *av@ac
	display *numbers
	display **numbers
	display *stack_a
	display *stack_b
end

define p_stack_a
	print stack_a
	set $node = stack_a
	set $first = stack_a
	print stack_a
	set $node = $node->next
	while ($node != 0 && $node != $first)
		print *$node
		set $node = $node->next
	end
end

define p_stack_b
	print stack_b
	set $node = stack_b
	set $first = stack_b
	print stack_b
	set $node = $node->next
	while ($node != 0 && $node != $first)
		print *$node
		set $node = $node->next
	end
end

define create_stack
	disp count
	disp i
	disp number
	disp *stack
end

define is_sorted
	disp i
	disp *current
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
run "0 1 2 3 4 5"
# run 65 45 71 6 30 51 12 50 74 92 88 5
main


