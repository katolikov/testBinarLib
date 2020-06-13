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
FILE SIZE: 100 mb
-------------------------------------------------------------
Benchmark                   Time             CPU   Iterations
-------------------------------------------------------------
BM_test_msg_deser   181395555 ns    102752333 ns            6
```

Test **serialization**
```
SERILIZATION: 
FORMAT FILE: messagepack 
FILE SIZE: 100 mb
-------------------------------------------------------------
Benchmark                   Time             CPU   Iterations
-------------------------------------------------------------
BM_test_msg_ser    2403917679 ns   1270791000 ns            1
```

### TEST №2
### libbson
Test **deserialization**
```
DESERILIZATION:
FORMAT FILE: bson 
FILE SIZE: 100 mb
-------------------------------------------------------------
Benchmark                   Time             CPU   Iterations
-------------------------------------------------------------
BM_test_bson_deser  470650786 ns    393687500 ns            2
```

### TEST №3
### libcbor
Test **deserialization**
```
DESERILIZATION:
FORMAT FILE: cbor 
FILE SIZE: 100 mb
-------------------------------------------------------------
Benchmark                   Time             CPU   Iterations
-------------------------------------------------------------
BM_test_cbor_deser 2146659555 ns   1926654000 ns            1
```

Test **serialization**
```
SERILIZATION:
FORMAT FILE: cbor
FILE SIZE: 100 mb
-------------------------------------------------------------
Benchmark                   Time             CPU   Iterations
-------------------------------------------------------------
BM_test_cbor_ser   1689037313 ns    687010000 ns            1

```
