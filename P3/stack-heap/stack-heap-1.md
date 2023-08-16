# stack-heap-1

## Voorbeeld 1

```c
void f() {
 int x;
 g(&x);
}
```

## Voorbeeld 2

```c
int *f() {
 int x;
 return &x;
}
```

## Voorbeeld 3

```c
int *f() {
 int *p = malloc(sizeof(int));
 return p;
}
```

## Voorbeeld 4

```c
void f() {
 int x;
 int **p = malloc(sizeof(int*));
 *p = &x;
}
```

## Voorbeeld 5

```c
void f() {
 int x;
 free(&x);
}
```
