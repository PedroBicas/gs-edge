# Monitoramento de Batimentos Cardíacos com ESP32 e TagoIO

## Integrantes
- Luigi Ferrara Sinno RM98047
- Pedro Henrique Bicas Couto RM99534

## Descrição do Problema

O monitoramento dos batimentos cardíacos é fundamental para a saúde, especialmente em casos onde manter uma frequência cardíaca específica é crucial. Este projeto utiliza um ESP32 para medir os batimentos cardíacos e enviar alertas caso a frequência cardíaca ultrapasse um limite definido.

## Visão Geral da Solução

O ESP32, um microcontrolador Wi-Fi de baixo custo, é utilizado para ler os dados dos batimentos cardíacos. Esses dados são enviados para o TagoIO, uma plataforma de IoT, que gerencia e processa os dados. Além disso, uma ação é configurada no TagoIO para enviar um e-mail de alerta caso a frequência cardíaca ultrapasse 90.


## Simulação no Wokwi e Integração com TagoIO

1. Acesse [TagoIO](https://tago.io/) e faça login na sua conta.

2. No painel principal, clique em "Dispositivos" e em seguida em "Adicionar Dispositivo".

3. Preencha as informações necessárias para adicionar o dispositivo representando o ESP32.

4. Após criar o dispositivo, clique no dispositivo recém-criado e vá para a aba "Variáveis".

5. Adicione uma variável chamada "heartRate" para armazenar os dados dos batimentos cardíacos.

6. Ainda na página do dispositivo, vá para a aba "Ações".

7. Crie uma nova ação para enviar um e-mail quando os batimentos cardíacos ultrapassarem 90.

   - Selecione como "Quando" a variável "heartRate".
   - Configure a condição para disparar a ação quando a variável for maior que 90.
   - Adicione a ação de e-mail, preenchendo o endereço de e-mail de destino, assunto e corpo da mensagem.

8. Salve as configurações da ação.

9. No TagoIO, vá para a aba "Configurações" no canto superior direito.

10. Selecione "Tokens" e copie o token do dispositivo associado ao seu ESP32.

11. Abra o código do projeto no [Wokwi](https://wokwi.com/projects/382150461848224769).

12. Encontre as variáveis no código referentes ao TagoIO:

    ```cpp
    const char *tagoIoToken = "token-do-dispositivo-no-tagoio";
    ```

13. Substitua `"token-do-dispositivo-no-tagoio"` pelo token do seu dispositivo TagoIO.

14. Salve as alterações e carregue o código no ESP32.

15. Envie dados simulados ou reais do ESP32 para o TagoIO.

16. Verifique o TagoIO para garantir que os dados estejam sendo registrados corretamente na variável "heartRate".

17. Confirme se a ação de e-mail no TagoIO é acionada corretamente quando os batimentos cardíacos ultrapassam 90.

Este guia abrange a simulação no Wokwi, a configuração do TagoIO, a integração do ESP32 com o TagoIO e a configuração de ações para enviar e-mails quando necessário.