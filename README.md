# Тестирование библиотек
### Тема
Производительность библиотек сериализации: двоичных форматов.

### Описание бенчмарка
Время **десериализации/сериализации** учитывается при чтение данных из памяти. 
Данные в память помещаются посредствам считывания их из файла.  

```
Run on (4 X 1600 MHz CPU s)
CPU Caches:
  L1 Data 32K (x2)
  L1 Instruction 32K (x2)
  L2 Unified 262K (x2)
  L3 Unified 4194K (x1)
Load Average: 1.85, 2.39, 3.10
```

### TEST №1
### msgpack
Test **deserialization**
```
DESERILIZATION: 
FORMAT FILE: messagepack
FILE SIZE: 3 mb
-------------------------------------------------------------
Benchmark                   Time             CPU   Iterations
-------------------------------------------------------------
BM_test_msg_deser     1550843 ns      1525876 ns          671
```

Test **serialization**
```
SERILIZATION: 
FORMAT FILE: messagepack 
FILE SIZE: 3 mb
-------------------------------------------------------------
Benchmark                   Time             CPU   Iterations
-------------------------------------------------------------
BM_test_msg_ser      29275885 ns     28191360 ns           25
```

### TEST №2
### libbson
Test **deserialization**
```
DESERILIZATION:
FORMAT FILE: bson 
FILE SIZE: 3 mb
-------------------------------------------------------------
Benchmark                   Time             CPU   Iterations
-------------------------------------------------------------
BM_test_bson_deser   22192522 ns     21599294 ns           34
```

### TEST №3
### libcbor
Test **deserialization**
```
DESERILIZATION:
FORMAT FILE: cbor 
FILE SIZE: 3 mb
-------------------------------------------------------------
Benchmark                   Time             CPU   Iterations
-------------------------------------------------------------
BM_test_cbor_deser        174 ns          170 ns      4653791
```

Test **serialization**
```
SERILIZATION:
FORMAT FILE: cbor
FILE SIZE: 3 mb
-------------------------------------------------------------
Benchmark                   Time             CPU   Iterations
-------------------------------------------------------------
BM_test_cbor_ser         28.8 ns         27.7 ns     29851637

```
