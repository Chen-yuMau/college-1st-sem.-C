CC      = gcc
CFLAGS  = -g
RM      = rm -f

objects = 0516043_hw10 0516043_hw3 0516043_hw4 0516043_hw6 0516043_hw7-1 0516043_hw7-2 0516043_hwLast coin_change exlinklist frominternet linklist 
all: $(objects)

$(objects): %: %.c
		$(CC) $(CFLAGS) -o $@ $<

clean veryclean:
    $(RM) $(objects)
