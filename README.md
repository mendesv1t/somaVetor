# Soma Vetor
Laboratório 2 da Disciplina: Programação Concorrente, no período 2024.1

## Contexto
Este programa concorrente realiza a soma de todos os elementos double de um vetor, passando para cada thread criada um lote de valores para essa soma,
no fim, com base na estrutura criada e retornada pela tarefa das threads, cada soma é mergeada a um valor único, que é testado para validar se é igual ao valor
gerado na última posição do aquivo ```nomeArquivo``` cujo nome é escolhido pelo usuário, que já nos traz a informação da soma esperada e também o tamanho do vetor na penúltima posição.


## Instruções
- Execute ```gcc -o geraVetor geraVetor.c``` para criar o executável que irá gerar um vetor de doubles aleatórios;
- Em seguida, rode ```./geraVetor``` e siga os passos indicados na linha de comando;
- Após criado o vetor, execute ```gcc -o main main.c```
- Após a compilação, rode o comando ```./main nomeArquivo```, aqui você irá executar o programa principal, passando como parâmetro o seu vetor de double gerado.
- Em seguida, o programa irá pedir a quantidade de threads que irá ser responsável pelos novos fluxos de execução.


## Observações
Foi utilizado o tipo double para minimizar casos de erro de precisão, por indicação da professora Silvana.
