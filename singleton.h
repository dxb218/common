�}�  �  ;m����Y�u
����r2n�Z0�y�6+���h�ه�'�ؗ�A�V+��4/��������I8�˯�~�ԶJ<��)Y(㡱�&���f�H���6���S�Q�W,���5N|�%ӯ��H���!Q��Z�+���w��A5�5*\O����+ڜ��ȚY��h*>Q�A|�1�J'�8�ESml��g�Ⲫp��D�
�ybm�E@�d5/	�V&�U�ڣF��k+�x����\�!/#.�_��f�2�C4s��{��ߪ
q`N�0O?ttJ<K�T�Ҵ��];�>�p�x���y���n�g+�j(�� �k����C�2S8��`�lg�sɼt��L�̩�����OIg������A"�����TFu�d�J�3�6���N���kq�2C�e�!F��ʣ�s��/G�����%�ߎ�ج���t�RT�|��o���ei@IU��4���]k�gr�e�aa��>���֧�#�s����

template <typename T>
class Singleton:Uncopyable
{
private:
    Singleton();
    ~Singleton();
    static void Init(){m_instance = new T();};

private:
    static T* m_instance;
    static pthread_once_t m_once;

public:
    static T* GetInstance()
    {
        pthread_once(&m_once,Init);
        return m_instance;
    };
};


template <typename T>
pthread_once_t Singleton<T>::m_once = PTHREAD_ONCE_INIT;

template <typename T>
T* Singleton<T>::m_instance = NULL;

#endif