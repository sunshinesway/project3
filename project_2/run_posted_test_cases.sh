#!/bin/bash

# Define an array of flag values
flags=(0 1 0 0 0 0 1 0 1 0 1 0 1 0 1 0 1 0 0 0)

# Loop through test cases
for i in {1..20}; do
  input_file="posted_test_cases/test${i}/ifile"
  expected_output="posted_test_cases/test${i}/ofile"
  output_file="posted_test_cases/test${i}/screen"
  screen_output_file="posted_test_cases/test${i}/myscreenoutput"
  commands_file="posted_test_cases/test${i}/Commands"

  # Run your program with the specified input, output, and commands files
  ./PJ2 "$input_file" "$output_file" "${flags[i-1]}" < "$commands_file" > "$screen_output_file"

  # Compare the program's output to the expected output
  diff "$expected_output" "$output_file"

  if [ $? -eq 0 ]; then
    echo "Test case $i: PASSED"
  else
    echo "Test case $i: FAILED"
  fi
done


Expected:
7
11.000000
13.000000
12.000000
14.000000
16.000000
17.000000
15.000000
8
9.000000
11.000000
12.000000
13.000000
16.000000
17.000000
15.000000
14.000000
9
8.000000
9.000000
12.000000
11.000000
16.000000
17.000000
15.000000
14.000000
13.000000
10
7.000000
8.000000
12.000000
11.000000
9.000000
17.000000
15.000000
14.000000
13.000000
16.000000
10
2.000000
7.000000
12.000000
11.000000
8.000000
17.000000
15.000000
14.000000
13.000000
9.000000
11
1.000000
2.000000
12.000000
11.000000
7.000000
17.000000
15.000000
14.000000
13.000000
9.000000
8.000000
7
11.000000
13.000000
12.000000
14.000000
16.000000
17.000000
15.000000
