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
Test **deserialization**
```
DESERILIZATION: 
FORMAT FILE 1: messagepack
FORMAT FILE 2: bson
FORMAT FILE 3: cbor
FILE SIZE: 100 mb
----------------------------------------------------------------
Benchmark                   Time             CPU      Iterations
----------------------------------------------------------------
1. BM_test_msg_deser    88057199 ns     79926000 ns            9
2. BM_test_bson_deser  464641318 ns    422559000 ns            2
3. BM_test_cbor_deser 2170780630 ns   1902517000 ns            1

```
### TEST №2
Test **serialization**
```
SERILIZATION: 
FORMAT FILE 1: messagepack
FORMAT FILE 2: cbor
FILE SIZE: 100 mb
----------------------------------------------------------------
Benchmark                   Time             CPU      Iterations
----------------------------------------------------------------
1. BM_test_msg_ser      68268596 ns     60745833 ns           12
2. BM_test_cbor_ser    901093079 ns    511093000 ns            1

```
