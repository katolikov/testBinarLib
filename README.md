# Тестирование библиотек
### Тема
Производительность библиотек сериализации: двоичных форматов.

### Описание бенчмарка
Время **десериализации/сериализации** учитывается при чтение данных из буфера. 
Данные в буфер помещаются посредствам считывания их из файла.  

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
FILE SIZE: 800 mb
-------------------------------------------------------------
Benchmark                   Time             CPU   Iterations
-------------------------------------------------------------
BM_test_msg_deser        1599 ns         1597 ns       449193
```

Test **serialization**
```
SERILIZATION: 
FORMAT FILE: messagepack 
FILE SIZE: 800 mb
-------------------------------------------------------------
Benchmark                   Time             CPU   Iterations
-------------------------------------------------------------
BM_test_msg_ser    6358901661 ns   3871422000 ns            1
```

### TEST №2
### libbson
Test **deserialization**
```
DESERILIZATION:
FORMAT FILE: bson 
FILE SIZE: 800 mb
-------------------------------------------------------------
Benchmark                   Time             CPU   Iterations
-------------------------------------------------------------
BM_test_bson_deser      27480 ns        27427 ns        25342
```

### TEST №3
### libcbor
Test **deserialization**
```
DESERILIZATION:
FORMAT FILE: cbor 
FILE SIZE: 800 mb
-------------------------------------------------------------
Benchmark                   Time             CPU   Iterations
-------------------------------------------------------------
BM_test_cbor_deser        190 ns          182 ns      2969449
```

Test **serialization**
```
SERILIZATION:
FORMAT FILE: cbor
FILE SIZE: 800 mb
-------------------------------------------------------------
Benchmark                   Time             CPU   Iterations
-------------------------------------------------------------
BM_test_cbor_ser         94.6 ns         93.6 ns      7982484

```
