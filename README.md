### Descrição

Projeto criado com intuito de ser um player de musica que permita colocar efeitos, como chuva, vento, fogo... entre outros sons. Utilizando QT com C++ e QML.

### Observação

O projeto acabou ficando uma especie de `hard coding` o correto seria refatora algumas rotinas para serem mais genericas e reutilizaveis, assim como padronizar os componentes visuais, vou refatorar e ajustar isso com o tempo pois ele ainda esta em desenvolvimento, o que existe ate agora é o mínimo funcional.

### Tecnologias

<div style="display: inline_block">
	<img align="center" alt="C++" src="https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white"/>
	<img align="center" alt="QT" src="https://img.shields.io/badge/QT-00ff00?style=for-the-badge&logoColor=white" />
	<img align="center" alt="CMAKE" src="https://img.shields.io/badge/QMAKE-0f246b?style=for-the-badge&logoColor=white" />
    <img align="center" alt="QML" src="https://img.shields.io/badge/QML-00ff00?style=for-the-badge&logoColor=white" />
</div>

## Dependências

| Name    | versão | Fonte                                           |
| ------- | ------ | ----------------------------------------------- |
| OpenSSL | 1.1.1  | https://slproweb.com/products/Win32OpenSSL.html |

Instalar o OpenSSL 1.1.1, possivelmente o diretorio vai ficar C:\OpenSSL-Win64, logo apos isso adicionar o diretorio "C:\OpenSSL-Win64\bin" ao Build Environment do QT, adicionar na variavel Path, ou adicionar ao .pro como `LIBS`

- [Forum de ajuda caso necessario](https://forum.qt.io/topic/95700/qsslsocket-tls-initialization-failed/34)

### Deploy

- Mudar aplicação para release para gerar o `.exe`
- Depois, estando na pasta release executar o seguinte comando `windeployqt.exe`

<b>OBS:</b> Nesse caso utilizei o compilador `MinGw 64-bit` e versão do `Qt 5.12.12`

### Imagens

É possível encontrar algumas imagens do resultado final na raiz do projeto em documentation/images
