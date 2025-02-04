Configura o temporizador de hardware para chamar a função de callback a cada 1 segundo.
# Simulação de Semáforo com Raspberry Pi Pico W no Wokwi

## Descrição
Este projeto implementa um **semáforo** utilizando um **Raspberry Pi Pico W** e a API do **Pico SDK** para gerenciamento de temporizadores. O sistema alterna entre os estados **vermelho, amarelo e verde** a cada **3 segundos**, seguindo o fluxo tradicional de um semáforo.

A simulação foi desenvolvida e testada na plataforma **Wokwi**, garantindo um ambiente de simulação realista para sistemas embarcados.

## 📌 Funcionalidades
- Alternância automática dos LEDs seguindo o padrão de um semáforo.
- Utilização de um **temporizador periódico** (`add_repeating_timer_ms()`) para alternância de estados.
- Impressão de mensagens no **monitor serial** indicando o estado atual do semáforo.
- Loop principal imprime mensagens a cada **1 segundo** para indicar que o sistema está em execução.

## 🛠️ Configuração do Hardware
### **Componentes Utilizados:**
- **Microcontrolador:** Raspberry Pi Pico W
- **LEDs:** Vermelho, Amarelo e Verde
- **Resistores:** 330Ω para cada LED

### **Conexões dos LEDs no Pico W:**
| LED       | GPIO |
|-----------|------|
| Vermelho  | 11   |
| Amarelo   | 12   |
| Verde     | 13   |

## 📜 Código Fonte (`semaforo.c`)
O código principal do semáforo está localizado no arquivo `semaforo.c` e utiliza a biblioteca **Pico SDK** para configuração dos GPIOs e gerenciamento do temporizador.

## 🖥️ Como Executar no Wokwi
1. **Abra o Wokwi** e crie um novo projeto com o Raspberry Pi Pico W.
2. **Adicione os arquivos do projeto** (`semaforo.c`, `CMakeLists.txt` e `diagram.json`).
3. **Configure o `diagram.json`** para definir os LEDs e suas conexões.
4. **Compile e execute a simulação**.
5. **Acompanhe as mensagens no monitor serial** para visualizar os estados do semáforo.

## 📂 Estrutura do Projeto
```
├── semaforo.c        # Código principal em C
├── CMakeLists.txt   # Configuração do CMake para compilação
├── diagram.json     # Configuração dos componentes no Wokwi
├── README.md        # Documentação do projeto
```

## 📝 Notas
- Este projeto foi desenvolvido para simulação no **Wokwi**, mas pode ser adaptado para rodar em hardware real.

## 👨‍💻 Autor
**Kauan Teixeira da Hora**


