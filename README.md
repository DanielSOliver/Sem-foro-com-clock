README - Controle de Semáforo com Raspberry Pi Pico

Este projeto implementa um controle básico de semáforo utilizando um Raspberry Pi Pico. O código foi desenvolvido em C e utiliza a SDK do Pico para controlar os LEDs que representam as luzes do semáforo (vermelho, amarelo e verde). O semáforo alterna entre os estados a cada 3 segundos, e após 9 segundos (3 ciclos), uma rotina é executada.

Descrição do Código
Estrutura do Código
Inclusão de Bibliotecas:

stdio.h: Para funções de entrada e saída padrão.

pico/stdlib.h: Para funções específicas do Raspberry Pi Pico, como manipulação de GPIO e temporizadores.

hardware/timer.h: Para manipulação de temporizadores de hardware.

Definição dos Pinos dos LEDs:

LED_VERMELHO: Pino GPIO 11.

LED_AMARELO: Pino GPIO 12.

LED_VERDE: Pino GPIO 13.

Variáveis Globais:

estado_semaforo: Controla o estado atual do semáforo (0: vermelho, 1: amarelo, 2: verde).

contador_tempo: Contador para controlar o tempo de execução da rotina.

Função de Callback:

repetir_callback: Função chamada a cada 3 segundos pelo temporizador. Alterna o estado do semáforo e incrementa o contador de tempo.

Função Principal:

main: Inicializa os pinos dos LEDs como saída, configura o temporizador periódico e entra em um loop infinito que verifica se o contador de tempo atingiu 3 ciclos (9 segundos) para executar uma rotina.

Funcionamento
Inicialização:

Os pinos dos LEDs são configurados como saída.

Um temporizador periódico é configurado para chamar a função repetir_callback a cada 3 segundos.

Alternância dos Estados do Semáforo:

A cada 3 segundos, a função repetir_callback é chamada, alternando o estado do semáforo entre vermelho, amarelo e verde.

O estado atual do semáforo é controlado pela variável estado_semaforo.

Controle de Tempo:

O contador contador_tempo é incrementado a cada chamada da função de callback.

Quando o contador atinge 3 (9 segundos), uma mensagem é exibida no console e o contador é resetado.

Loop Principal:

O programa entra em um loop infinito, onde verifica se o contador de tempo atingiu 3 ciclos.

Uma pequena espera (sleep_ms(100)) é adicionada para evitar o uso excessivo da CPU.


O semáforo começará a funcionar automaticamente, alternando entre os estados a cada 3 segundos.

Diagrama de Conexões

Pino do Pico	LED

GPIO 11	Vermelho

GPIO 12	Amarelo

GPIO 13	Verde

Considerações Finais

Este projeto é um exemplo básico de como controlar LEDs usando um Raspberry Pi Pico e pode ser expandido para incluir mais funcionalidades, como sensores de tráfego, botões de pedestres, etc. O código foi projetado para ser simples e fácil de entender, ideal para quem está começando com o desenvolvimento embarcado.
