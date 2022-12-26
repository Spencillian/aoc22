CC := gcc

.PHONY: all clean

all:
	@echo "Please pick a file to compile and run"

%: %.c
	@echo "Compiling..."
	${CC} $< -o out/$@
	@echo
	@echo "Running..."
	@./out/$@

clean:
	@echo "Cleaning up..."
	rm -rvf out/*
