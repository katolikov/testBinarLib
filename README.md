# Тестирование библиотек
Производительность библиотек сериализации: двоичных форматов

## TEST №1
### msgpack
Test **deserialization**
```
DESERILIZATION: 
FORMAT FILE: messagepack
FILE SIZE: 800 mb
msgpack test: 34.9128
```

Test **serialization**
```
SERILIZATION: 
FORMAT FILE: messagepack 
FILE SIZE: 800 mb
msgpack test: 64.2532
```

## TEST №2
### libbson
Test **deserialization**
```
DESERILIZATION:
FORMAT FILE: bson 
FILE SIZE: 800 mb
libbson test: 0.033449
```

Test **serialization**
```
SERILIZATION:
FORMAT FILE: bson 
FILE SIZE: 800 mb
libbson test: 0.063428
```
