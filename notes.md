
The overall syntax of a conversion specification is:

```
%[$][flags][width][.precision][length modifier]conversion
```




You have to implement the following conversions:
• %c Prints a single character.
• %s Prints a string (as defined by the common C convention).
• %p The void * pointer argument has to be printed in hexadecimal format.
• %d Prints a decimal (base 10) number.
• %i Prints an integer in base 10.
• %u Prints an unsigned decimal (base 10) number.
• %x Prints a number in hexadecimal (base 16) lowercase format.
• %X Prints a number in hexadecimal (base 16) uppercase format.
• %% Prints a percent sign.




Bonus list:
• Manage any combination of the following flags: ’-0.’ and the field minimum width under all conversions.
• Manage all the following flags: ’# +’ (Yes, one of them is a space)


Bonus Rules:
"#" flag:
	alternate form:
		x,X - prepend 0x to non 0 result.

"'" flag:
	Thousands grouping:
		d,i,u - apply locale denoted thousands seperator (default is blank, requires setlocale)

"0" flag:
	Left pad with 0's. Requires Minimum Width.
		(Bonus says this should apply to all conversions?)

"-" flag:
	Left justify content (OVERRIDES "0" FLAG). Requires Minimum Width.
		(Bonus says this should apply to all conversions?)

"." ???:
	Precision? I have no idea why this is included if we do not have any decimal places????

" " flag:
	Add a single space before a positive number produced by a signed conversion.
	Behaviour for unsigned conversions??? (Please test).

"+" flag:
	Add a single "+" sign before a positive number produced by a signed conversion.
