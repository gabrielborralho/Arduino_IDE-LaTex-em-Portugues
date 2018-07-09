# Arduino-LaTex

Neste repositório contem arquivos necessário para a inclusão de um código fonte Arduino (`.ino`) em documentos LaTex, onde o mesmo possa ter suas palavras reservadas destacas no corpo do texto.

O arquivo `arduino_code.tex` contém a definição do comando `\ArduinoSketch` e o ambiente ArduinoSketchBox que usam o pacote listings para definir o realce de sintaxe do Arduino IDE. O comando `ArduinoSketch` carrega o código de um sketch do Arduino do arquivo `.ino`, por isso é adequado para comprimentos de sketch que podem ocupar mais de uma página do documento. Outra maneira é utilziar o código do Arduino dentro de uma caixa colorida que pode ser ajustada dentro de uma coluna ou um pequeno espaço dentro do texto, é adequado para pequenos sketch que não ocupam mais de uma página ou para destacar partes do código.

O realce de sintaxe usado no arquivo `arduino_code.tex` pode ser visto em:
https://www.arduino.cc/en/Reference/HomePage.

```
|_examples (how to use each data structure and algorithm, organized by chapter)
|_src 
|___js (source code: JavaScript version)
|_____data-structures
|_______models (classes used by DS: Node, ValuePair, ...)
|_____others (other algorithms such as palindome checker, hanoi tower)
|___ts (source code: TypeScript version)
|_____data-structures
|_______models
|_____others
|_test (unit tests with Mocha and Chai for src)
|___js (tests for JavaScript code)
|___ts (tests for TypeScript code)
```

> Gabriel Borralho Board ATMega328P;

> ATMEL Recorder AVR USBasp;

# Results

## Assembly
<img src="https://i.imgur.com/kX73OUW.jpg"/>
