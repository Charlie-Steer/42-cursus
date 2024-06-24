prototype:
```c
int ft_printf(char const *, ...);
```

Implement following conversions:
- c. Constant length.
- s. ft_strlen().
- p. ft_itoa_base + ft_strlen()?
- d. ft_itoa + strlen.
- i. ft_itoa + strlen.
- u. ft_itoa + strlen?
- x. ft_itoa_base + strlen.
- X. ft_itoa_base + strlen.
- %. Constant length.

## Bonus
Manage any possible combinations:
- '-': padding on the **right** with 'blanks', rather than on the left with blanks or zeroes, as it overrides flag '0'.
- '0': zero-pads value for the conversion specifiers: **d, i, u, x, X**. Undefined behavior for other conversion specifiers. '0' flag is ignored if '-' appears.
- '.': radix point/character. Number afterwards specifies number of decimal places. For non fractionary types (d, i, u, x, X), it pads just like the regular minimum width value width but with '0' instead of ' '.
- Minimum width: number to determine the minimum width of the output. Gets padded with spaces if necessary.
Manage all the following flags:
- '\#': Converts the value of the argument to an alternate form.
	- For **x** & **X**, it prepends '0x' to the value.
- ' ': A blank should be left before a positive number (or empty string) produced by a signed conversion.
- '+': A sign is always placed before a number **(produced by a sign conversion?). '+' overrides a ' ' if both are used.
---

## Man Notes
arg 1: "format string"

- **directives**: ordinary characters that are written as is.
- **conversion specification**: introduced by '%'.
- **conversion specifier**: the final character of a 'conversion specification'.
Inbetween the '%' sign and the 'conversion specifier', there may be (in the following order):
- **flags** (zero or more).
- minimum field width.
- precision.
- length modifier.
- conversion specifier.

Error if insufficient arguments provided.

## Other Notes

### conversion specification structure
%(flags)(minimum field width).(decimal width)(conversion specifier)

## Concerns
- What about duplicate flags?
- Are macros legal? Better if global var?


## COMPLETION CHECKLIST!

- function starts with "ft_".
- Rules to compile BONUS added. Make sure that it doesn't compile bonus and add it to the library outright!!!!
