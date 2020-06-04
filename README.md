# Тестирование библиотек
Производительность библиотек сериализации: двоичных форматов

## Тест №1
### Msgpack
Тест **msgpack::unpack**
```
TEST READ FROM FILE: 
READ FROM FILE -> msgpack test: 0.001359
```

Тест **msgpack::pack**
```
WRITE TO BUFFER -> msgpack test: 6e-06
```

Тест **msgpack::unpack**
```
TEST READ FROM BUFFER: 
READ FROM BUFFER -> msgpack test: 1.1e-05
```

## Тест №2
### libbson
Тест **libbson::read_from_file_deserialization**
```
TEST READ FROM FILE: 
READ FROM FILE -> libbson test: 0.000608
```

Тест **libbson::cerialization**
```
WRITE TO BUFFER -> libbson test: 0.000238
```
