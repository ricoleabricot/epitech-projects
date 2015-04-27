.name		"Cryoclips"
.comment	"tonbouy"

top:
	st	r1, -511
	st	r1, -511
	st	r1, -511
	st	r1, -511
	st	r1, -511
	st	r1, -511
	st	r1, -511
	st	r1, -511
	st	r1, -511
	st	r1, -511
	st	r1, -511
	st	r1, -511
	st	r1, -511
	st	r1, -511
	st	r1, -511
	st	r1, -511
	st	r1, -511
	st	r1, -511
	st	r1, -511
	st	r1, -511
	st	r1, -511
	st	r1, -511
	st	r1, -511
	st	r1, -511
	st	r1, -511
	st	r1, -511
	st	r1, -511
	st	r1, -511
	st	r1, -511
	st	r1, -511
	st	r1, -511
	st	r1, -511
	st	r1, -511
	st	r1, -511
	st	r1, -511
	st	r1, -511
	st	r1, -511
	st	r1, -511
	st	r1, -511
	st	r1, -511
	st	r1, -511
	st	r1, -511
	st	r1, -511
	st	r1, -511
	st	r1, -511
	st	r1, -511
	st	r1, -511
	st	r1, -511
	st	r1, -511
	st	r1, -511
	st	r1, -511
	st	r1, -511
	st	r1, -511
	st	r1, -511
	st	r1, -511
	st	r1, -511
	st	r1, -511
	st	r1, -511
	st	r1, -511
	st	r1, -511
	st	r1, -511
	st	r1, -511
	st	r1, -511
	st	r1, -511
	st	r1, -511
	st	r1, -511
	st	r1, -511
	st	r1, -511
	st	r1, -511
	st	r1, -511
	st	r1, -511
	st	r1, -511
	st	r1, -511
	st	r1, -511
	st	r1, -511
	st	r1, -511
	st	r1, -511
	st	r1, -511
	st	r1, -511
	st	r1, -511
	st	r1, -511
	st	r1, -511
	st	r1, -511
	st	r1, -511
	st	r1, -511
	st	r1, -511
	st	r1, -511
	st	r1, -511
	st	r1, -511
	st	r1, -511
	xor	r15, r15, r15
	zjmp	%:top
replic:
	fork	%:test
	fork  	%:top
	fork	%:top
	fork	%:out
	fork	%:out
	xor	r15, r15, r15
	zjmp	%:replic
etape:
	xor	r15, r15, r15
	zjmp	%:out
start:
	fork	%:replic
	xor	r15, r15, r15
	zjmp	%:live
live:
	sti	r1, %:sustain, %1
sustain:
	live	%0
	xor	r15, r15, r15
	zjmp	%:live
bot:
	st	r1, 285
	st	r1, 285
	st	r1, 285
	st	r1, 285
	st	r1, 285
	st	r1, 285
	st	r1, 285
	st	r1, 285
	st	r1, 285
	st	r1, 285
	st	r1, 285
	st	r1, 285
	st	r1, 285
	st	r1, 285
	st	r1, 285
	st	r1, 285
	st	r1, 285
	st	r1, 285
	st	r1, 285
	st	r1, 285
	st	r1, 285
	st	r1, 285
	st	r1, 285
	st	r1, 285
	st	r1, 285
	st	r1, 285
	st	r1, 285
	st	r1, 285
	st	r1, 285
	st	r1, 285
	xor	r15, r15, r15
	zjmp	%:bot
test:
	fork    %:test2
test1:
	ld      %0, r12
	ld      %190056971, r10
	xor    	r15, r15, r15
	zjmp    %:timetowrite
test2:
	ld      %4, r12
	ld      %201916616, r10
timetowrite:
	sti     r10, r11, r12
	add     r12, r13, r12
	xor     r15, r15, r15
	fork    %:dehors
	zjmp    %:timetowrite
delete:
	ld	%1, r2
	sti	r2, %0, %27
	sti	r2, %0, %15
 	xor	r15, r15, r15
	zjmp	%:start
out:
	xor	r15, r15, r15
	zjmp	%:delete
	xor	r15, r15, r15
	zjmp	%:top
dehors:
