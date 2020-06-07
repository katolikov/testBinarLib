# Тестирование библиотек
Производительность библиотек сериализации: двоичных форматов
```
Run on (4 X 1600 MHz CPU s)
CPU Caches:
  L1 Data 32K (x2)
  L1 Instruction 32K (x2)
  L2 Unified 262K (x2)
  L3 Unified 4194K (x1)
Load Average: 2.93, 4.76, 5.40
```

## TEST №1
### msgpack
Test **deserialization**
```
DESERILIZATION: 
FORMAT FILE: messagepack
FILE SIZE: 800 mb
-------------------------------------------------------------
Benchmark                   Time             CPU   Iterations
-------------------------------------------------------------
BM_test_msg_deser  1933443967 ns   1591586000 ns            1
```

Test **serialization**
```
SERILIZATION: 
FORMAT FILE: messagepack 
FILE SIZE: 800 mb
-------------------------------------------------------------
Benchmark                   Time             CPU   Iterations
-------------------------------------------------------------
BM_test_msg_ser    13203831025 ns   6132893000 ns            1
```

## TEST №2
### libbson
Test **deserialization**
```
DESERILIZATION:
FORMAT FILE: bson 
FILE SIZE: 800 mb
-------------------------------------------------------------
Benchmark                   Time             CPU   Iterations
-------------------------------------------------------------
BM_test_bson_deser       36.3 ns         32.9 ns     24548914
```

## TEST №2
### libcbor
Test **deserialization**
```
DESERILIZATION:
FORMAT FILE: cbor 
FILE SIZE: 800 mb
-------------------------------------------------------------
Benchmark                   Time             CPU   Iterations
-------------------------------------------------------------
BM_test_cbor_deser        252 ns          241 ns      2235779
```

Test **serialization**
```
SERILIZATION:
FORMAT FILE: cbor
FILE SIZE: 800 mb
-------------------------------------------------------------
Benchmark                   Time             CPU   Iterations
-------------------------------------------------------------
BM_test_cbor_ser          154 ns          139 ns      5024657

```
