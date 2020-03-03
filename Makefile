objs = main.o backstage.o customer.o 
  
vms: $(objs)
	cc $(objs) -o vms

.PHONY: clean

clean:
	rm -f $(objs) vms


