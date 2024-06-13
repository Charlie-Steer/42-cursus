## Check character
```c
// CTYPE. Checks if int is alphabetical
int			ft_isalpha(int c);
// CTYPE. Checks if int is a digit
int			ft_isdigit(int c);
// CTYPE. Checks if int is a alphabetical or a digit
int			ft_isalnum(int c);
// CTYPE. Checks if int is a part of the ascii charset
int			ft_isascii(int c);
// CTYPE. Checks if int is a part of the ascii charset
int			ft_isprint(int c);
```
## Conversion
### Character Casing
```c
// CTYPE. Converts character to uppercase.
int			ft_tolower(int c);

// CTYPE. Converts character to uppercase.
int			ft_toupper(int c);
```
### Numbers
```c
// STDLIB. Converts a string to an integer.
int			ft_atoi(const char *str);

// NONSTANDARD. Converts an integer to a string.
char		*ft_itoa(int n);
```

## Strlen
```c
// STRING. Calculates length of a string. Null byte not included.
size_t		ft_strlen(const char *s);
```

## Trimming and splitting
```c
// NONSTANDARD. Allocates a new string that's the result of eliminating the characters from "set" from the beginning and end of "s1".
char		*ft_strtrim(char const *s1, char const *set);
```

```c
// NONSTANDARD. Allocates an array of strings that's the result of spliting string "s" on the character "c". The array ends with a NULL pointer.
char		**ft_split(char const *s, char c);
```

## Fill memory area
```c
// STRING. Fills a memory block with null bytes for "n" bytes.
void		ft_bzero(void *s, size_t n);

// STRING. Fills memory block with character "c" for "len" bytes.
void		*ft_memset(void *b, int c, size_t len);
```

## Copy and duplication
### Memory area
```c
// STRING. Copies "n" bytes from memory area "src" to memory area "dst". No reason to use instead of memmove except for speed.
void		*ft_memcpy(void *dst, const void *src, size_t n);

// STRING. memcopy() with overlap protection.
void		*ft_memmove(void *dst, const void *src, size_t len);
```
### Strings
```c
// STRING. Copies "dstsize" bytes from src to dst, or up to "src" null byte. Guarantees null-termination. Include byte for null byte in dstsize.
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);

// Returns a pointer to a new string which is a duplicate of s1.
char		*ft_strdup(const char *s1);
```
#### Sub-strings
```c
// NONSTANDARD. Allocates a new string of up to size "len", which is a copy of the substring s, starting at [start].
char		*ft_substr(char const *s, unsigned int start, size_t len);
```

## Concatenation
```c
// STRING. Concatenates "dstsize" bytes from src to the end of dst, or up to "src" null byte. Guarantees null-termination. Include byte for null byte in dstsize.
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
```

```c
// NONSTANDARD. Allocates a new string, with the result of concatenating s1 + s2.
char		*ft_strjoin(char const *s1, char const *s2);
```

## Finding chars and strings
### Characters
```c
// STRING. Returns the first ocurrence of byte "c" on memory area "s" up to "n" bytes.
void		*ft_memchr(const void *s, int c, size_t n);
```

```c
// STRING. Returns a pointer to the first occurrence of character "c" in string "s".
char		*ft_strchr(const char *s, int c);
// STRING. Returns a pointer to the last occurrence of character "c" in string "s".
char		*ft_strrchr(const char *s, int c);
```
### Strings
```c
// STRING. Returns the first occurence of string "needle" in string "haystack. Up to "len" bytes are checked.
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
```

## Comparison
```c
// STRING. Compares two areas of memory for up to "n" bytes. If result == 0 then comparison is equal. If result is > 0, s1 is bigger, else s1 is smaller than s2.
int			ft_memcmp(const void *s1, const void *s2, size_t n);

// STRING. Compares strings for "n" bytes. If result == 0 then comparison is equal. If result is > 0, s1 is bigger, else s1 is smaller than s2.
int			ft_strncmp(const char *s1, const char *s2, size_t n);
```

## Allocation
```c
// STDLIB. Allocates a block of memory of "count" * "size"
void		*ft_calloc(size_t count, size_t size);

```

## Write to file descriptor
```c
// Similar to STDIO (fputc()). Write char to file descriptor.
void		ft_putchar_fd(char c, int fd);
// Similar to STDIO (fputs()). Write string to file descriptor (without terminating \0).
void		ft_putstr_fd(char *s, int fd);
// Similar to STDIO (puts()). Write string to file descriptor (without terminating \0) followed by a line jump.
void		ft_putendl_fd(char *s, int fd);
// NONSTANDARD. Write integer to file descriptor (converted to string).
void		ft_putnbr_fd(int n, int fd);
```

## Apply function to characters of string
```c
// NONSTANDARD. Allocates a new string that's the result of the application of the function "f" to each character of the string "s". The signature of the function is constituted of an int for the index of the character within the string and a char for the character value itself.
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
// NONSTANDARD. Like strmapi() but modifies the string in-place (no allocation).
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
```

# Lists
### Creating and adding nodes to list
```c
// Creates a new node with content of any type.
t_list		*ft_lstnew(void *content);

// Adds a node "new" to the beginning of list "lst".
void		ft_lstadd_front(t_list **lst, t_list *new);
// Adds a node "new" to the end of the list "lst".
void		ft_lstadd_back(t_list **lst, t_list *new);
```

### Get size and last node
```c
// Returns the number of nodes in a list.
int			ft_lstsize(t_list *lst);

// Returns the last node of a list.
t_list		*ft_lstlast(t_list *lst);

```
### Delete Nodes
```c
// Frees the node's "lst" content variable by passing a function (probably free()). This is in case the content of the node is a pointer. If the content isn't a pointer, then it doesn't have to be freed. It will be automatically freed with the struct.
void		ft_lstdelone(t_list *lst, void (*del)(void *));
// Frees the node pointed to by "lst" and all the subsequent ones (probably with free()). The last pointer "next" of the list must be NULL.
void		ft_lstclear(t_list **lst, void (*del)(void *));
```
### Apply Function
```c
// Applies the function "f" to the contents of each node starting from "lst".
void		ft_lstiter(t_list *lst, void (*f)(void *));
// Allocate a new list with the content of the result of applying function "f" to each of the node's content from list "lst". function "del()" (probably free()) is passed in case an allocation fails and the content of each node and the list has to be freed.
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
```