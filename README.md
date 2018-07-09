# Arduino-LaTex

Neste repositório contem arquivos necessário para a inclusão de um código fonte Arduino (`.ino`) em documentos LaTex, onde o mesmo possa ter suas palavras reservadas destacas no corpo do texto.

O arquivo `arduino_code.tex` contém a definição do comando `\ArduinoSketch` e o ambiente ArduinoSketchBox que usam o pacote listings para definir o realce de sintaxe do Arduino IDE. O comando `ArduinoSketch` carrega o código de um sketch do Arduino do arquivo `.ino`, por isso é adequado para comprimentos de sketch que podem ocupar mais de uma página do documento. Outra maneira é utilziar o código do Arduino dentro de uma caixa colorida que pode ser ajustada dentro de uma coluna ou um pequeno espaço dentro do texto, é adequado para pequenos sketch que não ocupam mais de uma página ou para destacar partes do código.

O realce de sintaxe usado no arquivo `arduino_code.tex` pode ser visto em:
https://www.arduino.cc/en/Reference/HomePage.

# Modo de exemplo de arquivo `arduino_code.tex`
Para começar a incluir o código do Arduino em um documento `LATEX` simplesmente copie o arquivo `arduino_code.tex` para o diretório raiz do seu documento e use o comando `\input` no preâmbulo
```
\input{Arduino_code.tex}
```
# Modo de uso do ambiente `ArduinoSketchBox`
```
\begin{ArduinoSketchBox}{title}
  Código...
\end{ArduinoSketchBox}
```

# Exemplo do comando `\ArduinoSketch` de um código grande
A sintaxe de uso do comando `\ArduinoSketch` é muito simples, pois o comando usa dois parâmetros de entrada `arquivo.ino` que não devem ter a extensão .ino e Label para o código correspondente à caption do contador `Listing`.

```
\ArduinoSketch{arquivo.ino}{Legenda}
```
