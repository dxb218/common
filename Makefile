�}t  @  �c���)Y�u
��N�r74�gǗQٟ���=��k�x��'Rt���A���#/ʈy_��i���z�X8���
sF�R�S��{߄/�%g�S���g&*G�D(�NH�;����] c��j�@֩�v��Y�N0zW1�W�jh�M+[��˭�Kd�����}����3�9��9���aM�SN�Hԙ�	�ϋǉx�;������e�4]�XVC׭��_��{�N��|W����� ���O��?2�l00#f4zdqO�� �������+X"?�����X��1��>3���m�&v��#����5�f��p�/���}3��V�?(���=?�ȍ�$�`�%�n{J�g��(9`��1q�
�Z�6�G���\a+&�Ƈ^�y��H�w$M�rִ]e�!F��ʣ�s��/G�����%�ߎ�ج���t�RT�|��o���ei@IU��4���]k�gr�e�aa��>���֧�#�s����pp)
			# $(wildcard $(SOURCE_DIR2)/*.c) $(wildcard $(SOURCE_DIR2)/*.cpp)

#将目标定义为同名.o文件
OBJS    := $(patsubst %.c,%.o,$(patsubst %.cpp,%.o,$(SOURCE)))

all : $(TARGET)

objs : $(OBJS)

clean :
	rm -rf $(TARGET) $(OBJS)

rebuild: clean all

$(TARGET) : $(OBJS) 
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS) $(LDFLAGS) $(LIBS)