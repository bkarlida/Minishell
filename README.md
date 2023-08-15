# Minishell

Bu proje, temel bir Unix kabuğu (shell) yapmayı amaçlar. Kullanıcıların komutları girip çalıştırabileceği bir kabuk ortamı sunar. Proje, C programlama dilini, sistem çağrılarını ve komut işleme konularını içerir.

## Proje sahipleri
Murat mirsad Dırağa , Burak Karlıdağ
## Proje Amaçları

- Temel Unix kabuğu işlevlerini anlamak.
- Kullanıcıdan gelen komutları işlemek ve programları çalıştırmak.
- Komut satırı işlemlerini gerçekleştirebilmek.
- env (Çevresel değişkenler), redirection (dosya yönlendirmeleri) gibi shell özelliklerini desteklemek.

## Nasıl Çalışır?

1. **Çalıştırma:** Proje derlendikten sonra, `./minishell` komutuyla kabuk ortamını başlatabilirsiniz.

2. **Komut Girişi:** Kullanıcı komutları girebilir. Örnek olarak, `ls -l` veya `echo "Hello, world!"` gibi komutlar kabukta çalıştırılabilir.

3. **Komut İşleme:** Girilen komut parçalara ayrılır ve yürütülmeden önce işlenir. Birden fazla komut ve operatörler de desteklenir.

4. **Program Çalıştırma:** Girilen komutlar sistem çağrıları ve program çalıştırma işlevleriyle yürütülür.

5. **Çıkış:** Kabuk ortamından çıkmak için `exit` komutunu veya `Ctrl + D` tuş kombinasyonunu kullanabilirsiniz.

## Ayağa Kaldırma Adımları

1. Projeyi indirin.

2. İndirdiğiniz kaynak kodları bir dizine çıkarın.

3. Terminale gidin ve projenin ana dizinine gidin:

    ```bash
    cd /path/to/minishell
    ```

4. Projeyi derlemek için aşağıdaki komutları kullanabilirsiniz:

    ```bash
    make
    ```

    Bu komut, projeyi derleyecek ve "minishell" adlı bir yürütülebilir dosya oluşturacaktır.

5. Minishell'i başlatmak için aşağıdaki komutu kullanabilirsiniz:

    ```bash
    ./minishell
    ```

6. Projeyi temizlemek için aşağıdaki komutu kullanabilirsiniz:

    ```bash
    make clean
    ```

7. Projeyi sıfırlamak için aşağıdaki komutu kullanabilirsiniz:

    ```bash
    make fclean
    ```

Bu adımları izleyerek "Minishell" projesini derleyebilir ve kullanabilirsiniz.
