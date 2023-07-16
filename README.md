# Projeto Pinocch-IO
Um projeto de robô que desenvolvo por hobby enquanto pratico um pouco de robótica. Inicialmente, estou utilizando um simples `Arduino UNO` integrado a um driver de motor com dois motores e alguns poucos sensores. A programação do robô é toda feita em `C++` através do framework `Platform.IO`.

## O Protótipo
Tudo começa com uma ideia bem simples: um robô que apenas anda em linha reta e que fica parado quando o sensor ultrassônico percebe um obstáculo à frente.
<div style="display: flex">
    <img  src="docs/img/pinocch-io-frontal.jpeg" alt="Pinocch-IO Protótipo (frontal)"
    width="200">
    <img  src="docs/img/pinocch-io.jpeg" alt="Pinocch-IO Protótipo (frontal)"
    width="200">
    <img  src="docs/img/pinocch-io-lateral.jpeg" alt="Pinocch-IO Protótipo (frontal)"
    width="200">
    <img  src="docs/img/pinocch-io-posterior.jpeg" alt="Pinocch-IO Protótipo (frontal)"
    width="200">
</div>

## Eletrônica

| Componente | Tipo | Quantidade |
| ---------- | ---- | ---------- |
| Módulo Sensor Ultrassônico HC-SR04 | sensor | 1 |
| Módulo Sensor de Som LM393 | sensor | 1 |
| Driver Motor Ponte H L298N | ponte H | 1 |
| Motor DC 3-6V | motor | 2 |
| Adaptador para bateria 9V | alimentação | 1 |
| Bateria 9V | alimentação | 1 |

## Links externos
- [Quadro no Trello com andamento do projeto](https://trello.com/b/LF1wZCdL/project-pinnoch-io)
- [Diagramas e Fluxogramas]()