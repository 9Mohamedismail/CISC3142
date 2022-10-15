lab4:
	
	@echo "\nRunning program Ex3.17"
	@cd Exercise4 && g++ 3_17.cpp -o 3_17 && ./3_17
	@echo "\n\nRunning program Ex3.23"
	@cd Exercise4 && g++ 3_23.cpp -o 3_23 && ./3_23
	@echo "\n\nRunning program Ex4.28"
	@cd Exercise4 && g++ 4_28.cpp -o 4_28 && ./4_28
	@echo "\n\nRunning program Inflation"
	@cd Exercise4 && g++ Inflation.cpp -o Inflation && ./Inflation
	@echo "\n\nRunning program Nutrition calculator"
	@cd Exercise4 && g++ Nutrition_Calculator.cpp -o Nutrition_Calculator && ./Nutrition_Calculator

Lab5:
	@echo "\nRunning program Sum of Digits"
	@cd Exercise5 && g++ sumOfDigits.cpp -o sum && ./sum <sumValues.txt
	@echo "\n\nRunning program Prime Numbers"
	@cd Exercise5 && g++ primeNumbers.cpp -o prime && ./prime 
	@echo "\n\nRunning program Linear Regression"
	@cd Exercise5 && g++ linearRegression.cpp -o linear && ./linear <linearValues.txt
