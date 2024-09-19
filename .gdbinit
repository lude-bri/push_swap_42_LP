
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
	disp N
	disp (*stack_root)->size_a
	disp partition_size
	disp big_pivot
	disp small_pivot
end

define quick_a
	disp start
	disp end
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

define ra
	disp **stack
	disp *current
	disp *last_node
end

define rra
	disp *last_node
	disp *new_last_node
	disp **stack
end

define split_first
	disp partition_size
	disp big_pivot
	disp small_pivot
	disp end
	disp i
end

#  Start
fs cmd
break main_bonus
# run "1 2 4 3 0 3"
# run "1 122 14000 839"
# run 65 45 71 6 30 51 12 50 74 92 88 5
# run 0 9 1 8 2 7 3 6 4 5 < test.txt
# run -290 -980 -519 -489 -992 -252 -64 226 868 -41 -225 11 -333 703 199 -735 573 298 430 501 601 614 115 684 748 289 -422 -469 -453 -348 600 328 -847 789 340 -287 -150 974 -908 -786 -270 -31 -814 -900 -771 873 -103 -911 141 757 413 389 -798 -679 303 -136 -195 -832 401 -782 15 450 791 537 -354 722 492 896 -970 474 -464 -545 374 -323 661 482 -92 149 -83 -867 567 -739 721 508 -52 -789 -417 897 -683 739 383 -822 714 486 -36 -862 161 851 -741 996 589 733 -73 -506 -95 -371 243 -240 -829 1000 -761 -845 -883 -49 447 -915 838 491 942 -783 -707 373 -731 999 -600 -70 699 706 -650 -547 -179 563 -726 -648 -177 498 -942 -874 -313 -74 568 31 464 764 376 954 377 981 929 -501 904 -646 43 -347 777 -575 809 558 -813 -834 -200 -430 427 -589 -109 541 813 -875 793 804 -27 282 -588 -604 -546 587 -616 720 -173 -1 -523 -293 -695 -827 4 268 484 -541 -247 -456 666 360 705 924 -807 -957 -259 -644 -587 -603 494 -946 546 -975 694 -557 287 6 768 906 704 -386 -224 521 203 475 -764 837 -689 -6 -169 -974 446 -792 257 -193 -864 -998 653 -537 349 -266 332 -278 534 -226 967 -283 899 197 -625 -556 889 -579 860 -747 599 7 -230 814 311 697 701 -634 675 -488 651 -684 634 -723 493 -715 65 883 -698 -706 639 -373 382 194 753 263 246 117 264 790 961 -332 -361 -421 331 -362 -110 -793 81 168 -221 265 -884 -431 -737 -508 66 -442 -308 -358 -463 -28 292 738 214 -416 -661 461 859 798 627 -163 110 -850 386 324 459 734 -754 78 -552 -155 -460 995 151 603 135 395 871 774 -730 -986 -231 -291 -871 -898 123 -982 -471 -806 802 333 346 212 855 -515 -32 442 -330 593 103 -926 -539 744 -819 -44 850 -233 -300 -755 -385 -507 347 -439 48 266 -349 609 237 272 680 320 439 -18 364 206 909 -842 -590 -749 517 -402 -621 158 -727 20 -891 211 8 334 -889 727 -164 -415 743 -567 -14 51 523 402 -424 -669 779 -790 240 137 -412 823 -423 943 717 310 -769 28 -141 569 -516 251 -302 325 975 890 -756 -58 -299 192 759 -161 965 -491 19 -154 956 -10 -619 565 354 -794 912 -809 -410 -978 57 884 683 -465 -67 157 925 -839 403 997 -263 -666 -734 455 -331 -843 -708 -965 35 732 -411 -39 146 -773 678 -142 799 994 -271 737 -924 940 -694 -451 -728 876 -962 -34 984 616 -11 -309 312 -123 -530 583 0 -667 882 -273 -452 -153 -811 -118 947 -796 -560 -238 -800 615 -211 877
run	4 1 2 3
# run "" 1

main


