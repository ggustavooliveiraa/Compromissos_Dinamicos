Sistema de Gerenciamento de Compromissos
📌 Descrição

Este projeto consiste em um sistema de gerenciamento de compromissos desenvolvido em linguagem C. O programa realiza a leitura de dados a partir de um arquivo entrada.csv, armazena os compromissos em memória utilizando estruturas (struct) e permite:
Adicionar compromissos, Remover compromissos, Ordenar compromissos por diferentes critérios, Listar compromissos e Salvar automaticamente as alterações no arquivo. O sistema foi desenvolvido conforme os requisitos do trabalho acadêmico, incluindo múltiplos critérios de ordenação e persistência dos dados no arquivo.

🗂 Estrutura dos Dados

Cada compromisso contém os seguintes campos:

Ano.

Mês.

Dia.

Hora.

Minuto.

Duração (em horas).

Prioridade (1 a 5).

Nome.

Descrição.

Local.

Esses dados são armazenados na seguinte estrutura:

 Entrada de Dados:

Os compromissos são lidos automaticamente do arquivo: entrada.csv


📋 Funcionalidades

O sistema apresenta o seguinte menu:

Adicionar compromisso.

Remover compromisso.

Ordenar por data.

Ordenar por data e horário.

Ordenar por data e prioridade.

Ordenar por local, prioridade e duração (decrescente).

Listar compromissos.

Sair.

Critérios de Ordenação:
✔ Ordenar por data

Ordenação crescente por: Ano, Mês e Dia

✔ Ordenar por data e horário

Ordenação crescente por: Ano, Mês, Dia, Hora e Minuto.

✔ Ordenar por data e prioridade.

Ordenação por: Ano, Mês, Dia

Prioridade (maior prioridade primeiro)

✔ Ordenar por local, prioridade e duração (decrescente)

Ordenação por: Local (ordem alfabética), Prioridade (maior primeiro), Duração (maior primeiro).

Persistência:
Sempre que um compromisso é adicionado ou removido, o arquivo entrada.csv é atualizado automaticamente, garantindo que os dados permaneçam salvos mesmo após o encerramento do programa.
