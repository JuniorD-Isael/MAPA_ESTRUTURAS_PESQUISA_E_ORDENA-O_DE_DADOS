# Sistema de Verificação de RA - Árvore Binária de Busca

## 📋 Sobre o Projeto

Este projeto implementa um **Sistema de Verificação de RA** utilizando uma **Árvore Binária de Busca (ABB)** em linguagem C. O sistema permite verificar se um RA (Registro Acadêmico) existe em uma base de dados através de busca por prefixo caractere por caractere.

**Desenvolvido por:** Isael Dorneles Junior  
**RA:** 24522518-5  
**Disciplina:** Estruturas de Pesquisa e Ordenação de Dados

## 🎯 Funcionalidades

- ✅ Implementação de Árvore Binária de Busca (ABB)
- ✅ Inserção de RAs na árvore
- ✅ Busca por prefixo (caractere por caractere)
- ✅ Verificação completa de RA
- ✅ Interface interativa com o usuário
- ✅ Base de dados simulada com RAs válidos

## 🏗️ Estrutura do Projeto

```
MAPA_ESTRUTURAS_PESQUISA_E_ORDENA-O_DE_DADOS/
├── abb.c          # Código principal do sistema
└── README.md      # Documentação do projeto
```

## 🔧 Como Compilar e Executar

### Pré-requisitos
- Compilador GCC instalado
- Sistema operacional Linux/Unix ou Windows com ambiente de desenvolvimento C

### Passo a Passo

1. **Clone ou baixe o repositório:**
   ```bash
   git clone https://github.com/JuniorD-Isael/MAPA_ESTRUTURAS_PESQUISA_E_ORDENA-O_DE_DADOS.git
   cd MAPA_ESTRUTURAS_PESQUISA_E_ORDENA-O_DE_DADOS
   ```

2. **Compile o programa:**
   ```bash
   gcc -o abb abb.c
   ```

3. **Execute o programa:**
   ```bash
   ./abb
   ```

## 🚀 Como Usar

1. Execute o programa compilado
2. Digite um RA quando solicitado (formato: XXXXXXXX-X)
3. O sistema verificará caractere por caractere se o RA existe
4. Receberá o resultado da verificação

### Exemplo de Uso:

```
Sistema de Verificacao de RA
-----------------------------
Digite o RA para consulta: 24522518-5

--- Iniciando verificacao ---
Verificando prefixo: '2'...
>> Prefixo '2' valido. Continuando...
Verificando prefixo: '24'...
>> Prefixo '24' valido. Continuando...
...
--- Fim da verificacao por prefixo ---

Resultado: RA '24522518-5' localizado com sucesso no sistema!
```

## 📊 Base de Dados

O sistema possui os seguintes RAs pré-cadastrados:

- `1987654-1`
- `2034567-2`
- `1801234-3`
- `2154321-4`
- `24522518-5` (RA do desenvolvedor)
- `2009876-6`
- `1991234-7`

## 🔍 Algoritmos Implementados

### Árvore Binária de Busca (ABB)
- **Inserção:** O(log n) no caso médio, O(n) no pior caso
- **Busca:** O(log n) no caso médio, O(n) no pior caso
- **Busca por Prefixo:** Implementação customizada para verificação incremental

### Estruturas de Dados
```c
typedef struct No {
    char ra[20];
    struct No *esquerda;
    struct No *direita;
} No;
```

## 📚 Conceitos Aplicados

- **Árvores Binárias de Busca**
- **Algoritmos de Busca**
- **Busca por Prefixo**
- **Alocação Dinâmica de Memória**
- **Recursão**
- **Manipulação de Strings em C**

## 🧪 Testes Sugeridos

Para testar o sistema, experimente:

1. **RA Válido:** `24522518-5` ✅
2. **RA Inválido:** `99999999-9` ❌
3. **Prefixo Válido:** `1987654` (parte de um RA válido)
4. **Prefixo Inválido:** `9999` (não corresponde a nenhum RA)

## 📈 Complexidade

| Operação | Melhor Caso | Caso Médio | Pior Caso |
|----------|-------------|------------|-----------|
| Inserção | O(log n)    | O(log n)   | O(n)      |
| Busca    | O(log n)    | O(log n)   | O(n)      |
| Busca por Prefixo | O(log n) | O(log n) | O(n) |

## 🤝 Contribuição

Este é um projeto acadêmico desenvolvido como atividade da disciplina de Estruturas de Pesquisa e Ordenação de Dados.

## 📄 Licença

Este projeto está sob licença acadêmica e foi desenvolvido para fins educacionais.

---

**Universidade:** [Nome da Universidade]  
**Curso:** [Nome do Curso]  
**Disciplina:** Estruturas de Pesquisa e Ordenação de Dados  
**Ano:** 2025
