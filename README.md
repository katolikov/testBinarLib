# Тестирование библиотек
Производительность библиотек сериализации: двоичных форматов

## Тест №1
Тест **ifstream** (std::ios::binary) -> read 
```
Test READ FROM FILE: 
FILE SIZE: 10GB
First check: 0.001598
```
Тест **ofstream** (std::ios::binary) -> write 
```
Test WRITE FROM FILE: 
FILE SIZE: 10GB
First check WRITE: 0.003486
```
## Тест №2
## msgpack
Тест **msgpack::unpack**
```
Test READ FROM FILE: 
FILE SIZE: 1GB
First check READ: 0.000256
```
