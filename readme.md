# Tarefa 2 - Aula Síncrona 29/01 - Semáforo

**Autor:** Paulo Henrique de Farias Martins

## Funcionalidades do Semáforo

1. **Sequência inicial dos LEDs:**  
   O acionamento dos LEDs (sinais do semáforo) deve iniciar na cor vermelha, conforme orientação presente na Figura 1, alterando para a cor amarela e, em seguida, para a cor verde.

2. **Temporização:**  
   O temporizador deve ser ajustado para um atraso de 3 segundos (3.000 ms) entre as mudanças de estado dos LEDs.

3. **Callback do temporizador:**  
   A mudança de estado dos LEDs deve ser implementada por meio de uma função de callback do temporizador, conforme o exemplo trabalhado na aula síncrona (*repeating_timer_callback()*).

4. **Informação no loop principal:**  
   A rotina principal, presente no interior da estrutura de repetição `while`, deve imprimir alguma informação a cada segundo (1.000 ms). A mensagem enviada pela porta serial fica a critério do discente.



## Instruções

Siga estes 3 passos simples para executar o projeto:

1. **Clonar o projeto:**  
   Clone este repositório para sua máquina local.

2. **Importar o projeto:**  
   Importe o projeto utilizando a extensão *Raspberry Pico Pi* no seu ambiente de desenvolvimento.

3. **Executar o projeto:**  
   Execute o projeto utilizando a extensão *Raspberry Pico Pi* , para gerar o arquivo de build.

4. **Executar o Simulador**  
   Execute o projeto, com a extenção da wokwi instalada, clicando no arquivo *diagram.json*.





