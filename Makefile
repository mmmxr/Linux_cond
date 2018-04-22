.PHONY:clean
cond:cond.c
	gcc -o $@ $^ -lpthread
clean:
	rm -rf cond
