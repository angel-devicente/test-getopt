Quick test to debug issue with getopt when used for non-global parameters.

$ gcc -o test_long test_long.c

,----
| $ ./test_long < sample_commands.txt
|   -- option i
|   -- option a
| 
| 
|   -- option i
|   -- option a
| 
| 
| cmd: invalid option -- '-'
|   -- option unknown
|   -- option a
|   -- option a
| 
| 
|   -- option i
|   -- option a
`----

