## Desenho Básico

![1](https://github.com/estudiohacker/robo-desenhista/blob/master/assets/desenho01.png?raw=true)

```C
for (var count = 0; count < 4; count++){
  moveForward(100); // tamanho do lado do quadrado
  turnRight(90);
}
``` 

![2](https://github.com/estudiohacker/robo-desenhista/blob/master/assets/desenho02.png?raw=true)

```C
// nesse loop definimos quantas vezes o quadrado será desenhado - 3 nesse caso
for (var count1 = 0; count1 < 3; count1++){ 
  // nesse loop desenhamos os lados do quadrado
  for (var count = 0; count < 4; count++){ 
    moveForward(100); // definir o tamanho do lado do quadrado
    turnRight(90);
  }
  // aqui definimos quantos graus o quadrado deve rotacionar. 
  // para descobrir o ângulo, dividimos 360 pela quantidade de vezes que o quadrado é desenhado
  // nesse caso 360/3 = 120
  turnRight(120);
}
``` 

![3](https://github.com/estudiohacker/robo-desenhista/blob/master/assets/desenho03.png?raw=true)

```C
for (var count = 0; count < 2; count++){
  moveForward(100); // tamanho do lado do losango
  turnRight(60);
  moveForward(100); // tamanho do lado do losango
  turnRight(120);
}
```

![4](https://github.com/estudiohacker/robo-desenhista/blob/master/assets/desenho04.png?raw=true)

```C
for (var count = 0; count < 360; count++){
  moveForward(1);
  turnRight(1);
}
```

![5](https://github.com/estudiohacker/robo-desenhista/blob/master/assets/desenho05.png?raw=true)

```C
// nesse loop definimos quantas vezes o círculo será desenhado - 16 nesse caso
for (var count1 = 0; count1 < 16; count1++){
  // desenhar o círculo
  for (var count = 0; count < 360; count++){
    moveForward(1);
    turnRight(1);
  }
  jumpForward(50); // testar outros valores
  // para descobrir o ângulo, dividimos 360 pela quantidade de vezes que o quadrado é desenhado
  // nesse caso 360/16 = 22.5
  turnRight(22.5);
}

![6](https://github.com/estudiohacker/robo-desenhista/blob/master/assets/desenho06.png?raw=true)

```C
// círculo menor
for (var count = 0; count < 36; count++){
  moveForward(5);
  turnRight(10);
}

//círculo maior
for (var count = 0; count < 36; count++){
  moveForward(10);
  turnRight(10);
}
```


