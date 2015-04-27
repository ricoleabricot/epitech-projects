.name		"Kafei rules the World V42"
.comment	"Overwritting PYRO !!!"

		sti	r1,%:live,%1
live:
		live	%1
		xor	r15,r15,r15
		zjmp	%:live