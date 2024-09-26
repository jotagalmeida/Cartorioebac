#include <stdio.h> //biblioteca de comunicação com o usuário 
#include <stdlib.h>//biblioteca para alocação de espaço de memória 
#include <locale.h>//biblioteca de alicações de texto por região 
#include <string.h>//bliblioteca resposável por cuidar das strings

int registro()//Função responsável por cadastrar os usuários no sistema
{	
	//Início criação de variáveis/ strings
	char arquivo[40];
	char cpf[40]; 
	char nome [40];
	char sobrenome[40];
	char cargo [40];
	//Final da criação de variáveis/ strings	
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informação do usuário 
	scanf("%s", cpf); //%s é usado para leitura de strings 
	
	strcpy(arquivo, cpf); // Resposável por copiar os valores das strings
	
	FILE *file; //Cria arquivo
	file = fopen(arquivo, "w");	//Abrir e ler o arquivo (w vem de "write") 
	fprintf(file, cpf); //salvo o valor da variavel
	fclose(file); //fecho o arquivo 
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
		
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Não foi possível abrir o arquivo, não localizado! \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
			
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletador: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file; 
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema!\n");
		system("pause");
	}
		
}

int main()
{
	int opcao=0;//Definir variavel
	int laco=1;
	char senhadigitada[10]="a";
	int comparacao;
	
	printf("### Cartório da EBAC ### \n\n");
	printf("Login de administrador!\n\nDigite a sua senha: ");
	scanf("%s",senhadigitada);
	printf("\n");
	
	comparacao = strcmp(senhadigitada, "admin");//Usamos esta função regida pela biblioteca para comparar na memória a senha gravada e digitada
	
	if(comparacao == 0)
	{
		
		for(laco=1;laco=1;)
		{
		
			system("cls"); //Usamos este comando para apagar da tela tudo que veio anteriormente
	
			setlocale(LC_ALL, "Portuguese");//Definir a linguagem 
	
			printf("### Cartório da EBAC ### \n\n");//inicio do menu
		
			printf("Escolha a opção desejada do menu: \n\n");
		
			printf("\t1 - Registrar nomes \n");
			printf("\t2 - Consultar nomes \n");
			printf("\t3 - Deletar nomes \n");
			printf("\t4 - Sair do sistema\n\n\n");
			printf("Opção: ");//fim do menu
		
			scanf("%d", &opcao);//%d usamos para armazenar uma variável do tipo inteiro através do usuário
		
			system("cls"); //usamos este comando para apagar da tela tudo que venio anteriormente
		
			switch(opcao)//inicio da seleção do menu
			{
				case 1:
				registro();//Chamada de funções 
				break;
				
				case 2:	
				consulta();	
				break;
				
				case 3:
				deletar();
				break;
				
				case 4:
				printf("Obrigado por utilizar o sistema!\n");
				return 0;
				break;
								
				default:
				printf("Essa opção não está disponível!\n");
				system("pause");
				break;
			}//fim da selecao		
		}
	}
	
	else
		printf("Senha incorreta!");
}

