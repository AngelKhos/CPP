#!usr/bin/bash

rm -f test.log

if [ -z "$1" ] || [ -z "$2" ]; then
	read -p 'Please enter a number of iterations: ' iterations
	read -p 'Please enter a number of values: ' values

	echo "Running $iterations tests for $values values"

	for ((i = 0; i < $iterations; i++)); do
		./PmergeMe $(shuf -i 0-"$values" -n "$values" | tr "\n" " ") >> test.log
	done

	echo "Total number of tests: $i"
	echo -n "Success: "
	cat < test.log | grep -c "successfully sorted"
	echo -n "Failure: "
	cat < test.log | grep -c "not sorted"
	exit 0
fi



echo "Running $1 tests for $2 values"

for ((i = 0; i < $1; i++)); do
	./PmergeMe $(shuf -i 0-"$2" -n "$2" | tr "\n" " ") >> test.log
done

echo "Total number of tests: $i"
echo -n "Success: "
cat < test.log | grep -c "successfully sorted"
echo -n "Failure: "
cat < test.log | grep -c "not sorted"