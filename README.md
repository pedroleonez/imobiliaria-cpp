# Sistema de Agendamento de Imobiliária

**Disciplina:** Linguagem de Programação I (LP1)  
**Avaliação:** Terceira Unidade  
**Linguagem:** C++11

## 📋 Descrição do Projeto

Sistema desenvolvido em C++ para gerenciar agendamentos de visitas a imóveis em uma imobiliária. O sistema otimiza a distribuição de imóveis entre corretores avaliadores, utilizando algoritmos de proximidade geográfica para minimizar tempo de deslocamento.

## 🎯 Funcionalidades

- **Cadastro de Corretores:** Registro de corretores com identificação de quais são avaliadores
- **Cadastro de Clientes:** Sistema de registro de clientes interessados
- **Cadastro de Imóveis:** Gerenciamento de imóveis com diferentes tipos (Casa, Apartamento, Terreno)
- **Geração de Agendamentos:** Distribuição automática e otimizada de visitas entre corretores avaliadores
- **Otimização de Rotas:** Utilização do algoritmo de Haversine para calcular distâncias geográficas

## 🏗️ Arquitetura do Sistema

### Estrutura de Classes

```
📦 Sistema Imobiliária
├── 🏢 Corretor
│   ├── ID único
│   ├── Telefone
│   ├── Status de avaliador
│   ├── Coordenadas geográficas (lat, lon)
│   └── Nome
├── 👤 Cliente
│   ├── ID único
│   ├── Telefone
│   └── Nome
├── 🏠 Imovel
│   ├── ID único
│   ├── Tipo (Casa/Apartamento/Terreno)
│   ├── ID do proprietário
│   ├── Coordenadas geográficas (lat, lon)
│   ├── Endereço
│   └── Preço
└── 📅 Agendamento
    └── Algoritmo de distribuição otimizada
```

### Algoritmo de Otimização

O sistema implementa um algoritmo que:
1. Filtra apenas corretores que são avaliadores
2. Distribui imóveis igualmente entre os avaliadores disponíveis
3. Para cada corretor, calcula a rota mais eficiente usando:
   - **Fórmula de Haversine** para distâncias geográficas
   - **Algoritmo guloso** para minimizar deslocamentos
   - **Cálculo de tempo** considerando 2 minutos por quilômetro + 1 hora por visita

## 🚀 Como Executar

### Pré-requisitos

- Compilador C++ com suporte ao C++11 ou superior
- Make (para usar o Makefile)
- Sistema Linux/Unix (recomendado)

### Compilação

```bash
# Usando o Makefile
make

# Ou compilação manual
g++ -std=c++11 -Wall -Wextra -pedantic -o imobiliaria main.cpp Corretor.cpp Cliente.cpp Imovel.cpp Agendamento.cpp
```

### Execução

```bash
# Executar com entrada padrão
./imobiliaria

# Executar com arquivo de entrada
./imobiliaria < teste1_entrada.txt

# Salvar saída em arquivo
./imobiliaria < teste1_entrada.txt > minha_saida.txt
```

### Limpeza

```bash
make clean
```

## 📊 Formato de Entrada

O sistema recebe dados na seguinte sequência:

```
<número_de_corretores>
<telefone> <é_avaliador> <latitude> <longitude> <nome>
...

<número_de_clientes>
<telefone> <nome>
...

<número_de_imóveis>
<tipo> <id_proprietário> <latitude> <longitude> <preço> <endereço>
...
```

### Exemplo de Entrada

```
2
123456789 1 -3.74 -38.52 João
987654321 1 -3.75 -38.55 Maria

2
111222333 Carlos
444555666 Ana

3
Casa 1 -3.75 -38.50 300000.0 RuaA123
Apartamento 2 -3.77 -38.47 200000.0 RuaB456
Terreno 1 -3.76 -38.53 150000.0 RuaC789
```

## 📈 Formato de Saída

O sistema gera um cronograma otimizado no formato:

```
Corretor <ID>
<HH:MM> Imóvel <ID>
<HH:MM> Imóvel <ID>
...

Corretor <ID>
<HH:MM> Imóvel <ID>
...
```

### Exemplo de Saída

```
Corretor 1
09:04 Imóvel 1
10:11 Imóvel 3

Corretor 2
09:18 Imóvel 2
```

## 🧪 Testes

O projeto inclui casos de teste para validação:

- **teste1_entrada.txt / teste1_saida.txt:** Caso básico com 2 corretores e 3 imóveis
- **teste2_entrada.txt / teste2_saida.txt:** Caso intermediário
- **teste3_entrada.txt / teste3_saida.txt:** Caso complexo

### Executar Testes

```bash
# Teste 1
./imobiliaria < teste1_entrada.txt > minha_saida1.txt
diff teste1_saida.txt minha_saida1.txt

# Teste 2
./imobiliaria < teste2_entrada.txt > minha_saida2.txt
diff teste2_saida.txt minha_saida2.txt

# Teste 3
./imobiliaria < teste3_entrada.txt > minha_saida3.txt
diff teste3_saida.txt minha_saida3.txt
```

## 🔧 Detalhes Técnicos

### Principais Características

- **Padrão de Programação:** Orientação a Objetos
- **Gerenciamento de Memória:** Uso eficiente de containers STL
- **Algoritmos:** Haversine para cálculos geográficos, algoritmo guloso para otimização
- **Precisão:** Cálculos de tempo em minutos com arredondamento adequado

### Bibliotecas Utilizadas

- `<iostream>` - Entrada/Saída
- `<vector>` - Containers dinâmicos
- `<string>` - Manipulação de strings
- `<cmath>` - Funções matemáticas
- `<map>` - Estruturas associativas
- `<algorithm>` - Algoritmos STL
- `<iomanip>` - Formatação de saída

### Complexidade

- **Espacial:** O(n + m + k) onde n=corretores, m=clientes, k=imóveis
- **Temporal:** O(k² × a) onde k=imóveis e a=avaliadores (devido ao algoritmo guloso)

## 📝 Estrutura de Arquivos

```
imobiliaria-cpp/
├── main.cpp                  # Programa principal
├── Corretor.cpp/.h           # Classe Corretor
├── Cliente.cpp/.h            # Classe Cliente
├── Imovel.cpp/.h             # Classe Imovel
├── Agendamento.cpp/.h        # Lógica de agendamento
├── teste1_entrada.txt        # Casos de teste
├── teste1_saida.txt
├── teste2_entrada.txt
├── teste2_saida.txt
├── teste3_entrada.txt
├── teste3_saida.txt
├── minha_saida1.txt          # Arquivos de saída gerados
├── minha_saida2.txt
├── minha_saida3.txt
├── imobiliaria               # Executável compilado
├── Makefile                  # Script de compilação
└── README.md                 # Documentação
```

## 🎓 Objetivos Pedagógicos

Este projeto demonstra competências em:

- **Programação Orientada a Objetos:** Encapsulamento, classes e objetos
- **Estruturas de Dados:** Uso eficiente de containers STL
- **Algoritmos:** Implementação de algoritmos de otimização
- **Boas Práticas:** Código limpo, modular e bem documentado
- **Gerenciamento de Projeto:** Makefile
- **Resolução de Problemas:** Modelagem de sistema real

## 👥 Autoria

Projeto desenvolvido por Pedro Leonez como avaliação da Terceira Unidade da disciplina de Linguagem de Programação I.

---

**Nota:** Este sistema foi desenvolvido com foco acadêmico, demonstrando aplicação prática de conceitos de programação em C++ para resolução de problemas reais de otimização logística.