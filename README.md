# 📌 Projeto: Comunicação Serial e Controle de Periféricos

## 🎯 Objetivos
- Compreender o funcionamento e a aplicação de comunicação serial em microcontroladores.
- Aplicar os conhecimentos adquiridos sobre UART e I2C na prática.
- Manipular e controlar LEDs comuns e LEDs endereçáveis WS2812.
- Fixar o estudo do uso de botões de acionamento, interrupções e debounce.
- Desenvolver um projeto funcional que combine hardware e software.

---

## 📝 Descrição do Projeto
Este projeto utiliza a placa **BitDogLab** para integrar diversos componentes eletrônicos e explorar técnicas de comunicação serial. O sistema permite a entrada de caracteres via **Serial Monitor**, controle de LEDs RGB e interação com botões físicos.

### 🔧 Componentes Utilizados
- **Matriz 5x5 de LEDs WS2812** (endereçáveis) – GPIO 7
- **LED RGB** – GPIOs 11, 12 e 13
- **Botão A** – GPIO 5
- **Botão B** – GPIO 6
- **Display SSD1306** (via I2C) – GPIO 14 e GPIO 15

---

## ⚙️ Funcionalidades do Projeto

### 1️⃣ Modificação da Biblioteca `font.h`
✍️ **Objetivo:** Adicionar caracteres minúsculos à biblioteca `font.h`.
- Utilize a criatividade para desenhar os novos caracteres.
- Eles devem ser compatíveis com o **display SSD1306**.

### 2️⃣ Entrada de Caracteres via PC
🖥️ **Objetivo:** Exibir caracteres recebidos via **Serial Monitor** no **display SSD1306**.
- Cada caractere digitado no Serial Monitor será mostrado no display.
- Se um número entre **0 e 9** for digitado, um **símbolo correspondente** será exibido na **matriz 5x5 WS2812**.

### 3️⃣ Interação com o **Botão A**
🟢 **Objetivo:** Alternar o estado do LED **Verde**.
- Pressionar o botão A **liga/desliga** o LED verde.
- Feedback da operação:
  - Mensagem informativa no **display SSD1306**.
  - Mensagem descritiva no **Serial Monitor**.

### 4️⃣ Interação com o **Botão B**
🔵 **Objetivo:** Alternar o estado do LED **Azul**.
- Pressionar o botão B **liga/desliga** o LED azul.
- Feedback da operação:
  - Mensagem informativa no **display SSD1306**.
  - Mensagem descritiva no **Serial Monitor**.

---

## 🚀 Como Executar o Projeto
1. **Configure o ambiente de desenvolvimento** (VS Code + extensões necessárias).
2. **Conecte a placa BitDogLab** ao PC via USB.
3. **Compile e carregue o código** na placa.
4. **Abra o Serial Monitor** no VS Code para testar a entrada de caracteres.
5. **Interaja com os botões e LEDs** para verificar as funcionalidades.

---

## 🎥 Vídeo Demonstrativo
📌 Assista ao vídeo do projeto no link abaixo:
[https://www.youtube.com/shorts/iFL4yYB_dQg]

---

## 📌 Conclusão
Este projeto é uma excelente introdução à comunicação serial e ao controle de periféricos com microcontroladores. A interação entre **hardware e software** permite fixar conceitos essenciais de eletrônica e programação embarcada.

🔗 **Fique à vontade para contribuir e sugerir melhorias!** 🚀

