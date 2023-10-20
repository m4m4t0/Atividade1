import hashlib

class ErroNomeMenor(Exception):
    def __init__(self):
        super().__init__()

class ErroNomeEspaco(Exception):
    def __init__(self):
        super().__init__()

class ErroNivelNotInt(Exception):
    def __init__(self):
        super().__init__()

class ErroNivelFora(Exception):
    def __init__(self):
        super().__init__()

class ErroCadastro(Exception):
    def __init__(self):
        super().__init__()

class Usuario:
    def __init__(self, nome, senha, nivel):
        #recebe os parâmetros iniciais (para a senha é usado um método da classe)
        if self.usuario_valido(nome):
            self.nome = nome
        
        self.senha_hash = self.senha_em_hash(senha)

        try:
            nivel = int(nivel)

        except ValueError:
            raise ErroNivelNotInt
        
        if self.nivel_valido(nivel):
            self.nivel = nivel


    def usuario_valido(self, nome):
        # verifica se o nome de usuário escolhido é válido
        if (len(nome) < 6):
            raise ErroNomeMenor
        elif (' ' in nome):
            raise ErroNomeEspaco
        else: 
            return True
    
    def senha_em_hash(self, senha):
        # faz uso de hash para armazenar a senha
        senha_sha256 = hashlib.sha256()
        senha_sha256.update(senha.encode("utf-8"))
        
        return senha_sha256.hexdigest()
    
    def verificar_senha_usuario(self, senha, usuario):
        # verifica se o usuário e senhas digitados estão corretos
        if (self.senha_hash == self.senha_em_hash(senha) and self.nome == usuario):
            print('\nLogin efetuado com sucesso!')
        else:
            raise ErroCadastro

    def acesso_nivel(self, nivel):
        # verifica se o usuário tem acesso à esse nível
        if self.nivel >= nivel:
            print('Acesso permitido.')
        else:
            print(f'Acesso negado para usuários de nível {self.nivel}.')

    def nivel_valido(self, nivel):
        if (not isinstance(nivel, int)):
            raise ErroNivelNotInt

        if (nivel not in [1, 2, 3]):
            raise ErroNivelFora

        else: return True


usuario = str(input("Digite um nome de usuário com no mínimo 6 caracteres e sem espaços: "))
senha = str(input("Digite sua nova senha: "))
nivel = input("Digite o nível de usuário de 1 a 3, sendo 3 o nível mais alto e 1 o mais baixo: ")

print('\nAguarde...')

while (1):
    try:
        dados = Usuario(usuario, senha, nivel)
        break

    except ErroNivelFora:
        nivel = input("\nNível tem que estar entre 1 e 3!\nDigite outro valor para o nível da conta: ")

    except ErroNivelNotInt:
        nivel = input("\nNível tem que ser um número inteiro!\nDigite outro valor para o nível da conta: ")

    except ErroNomeEspaco:
        usuario = input("\nNome de usuário não pode ter espaços!\nDigite outro nome de usuário: ")

    except ErroNomeMenor:
        usuario = input("\nNome de usuário precisa ter 6 ou mais caracteres!\nDigite outro nome de usuário: ")

print('Cadastro efetuado com sucesso!\nEfetue seu primeiro login.\n')
input_usuario = str(input("Digite o nome de usuário: "))
input_senha = str(input("Digite a senha de usuário: "))

while(1):
    try:
        dados.verificar_senha_usuario(input_senha, input_usuario)
        break
    except ErroCadastro:
        print("Login falhou, senha e/ou usuário incorretos, tente novamente.\n")
        input_usuario = str(input("Digite o nome de usuário: "))
        input_senha = str(input("Digite a senha de usuário: "))
        

input_nivel = int(input('Digite o nível de acesso desejado: '))
dados.acesso_nivel(input_nivel)