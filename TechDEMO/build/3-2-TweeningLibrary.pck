GDPC                                                                               D   res://.import/enemyBlack1.png-0f9d8d722ff15e3c240393a28c6c5de8.stex �      �	      ��4]iv�a��9^<   res://.import/icon.png-487276ed1e3a0c39cad0279d744ee560.stex�S      �      &�y���ڞu;>��.pH   res://.import/playerShip1_blue.png-f0ced591f3114b0942d5fcc216ee32a9.stex�$      �      ��X�Bu<��ݎ�CJHL   res://.import/playerShip1_green.png-4ec31ecb47dff1e1c73f710296640692.stex   @6      �      ݵ��[��n����L   res://.import/playerShip3_orange.png-8962c97ec7ba19d91ab25996dd16b951.stex   H      �      ��gS���#a-Am�c   res://default_env.tres  p      �       um�`�N��<*ỳ�8   res://homework/Ship.tscn 	      �       �����Yn�'�Gs6   res://homework/Tweening.gdns�	      �       ���97=�9rV��ơ�   res://homework/Tweening.tscn�
      �      �>��ҝ��r�w1�	(   res://homework/scripts/Tweening.gd.remap`t      4       �Ǔ�=k+1��QK�L��$   res://homework/scripts/Tweening.gdc p      d	      �'�� 	���8�32�0   res://homework/sprites/enemyBlack1.png.import   �!      �      h�G����>,bo��}4   res://homework/sprites/playerShip1_blue.png.import  `3      �      Gߟ�QV=��dXﭰ�U4   res://homework/sprites/playerShip1_green.png.import  E      �      ��N
^a�H�C�ˈ;�4   res://homework/sprites/playerShip3_orange.png.import�P      �      ����%�$2G~�UH0   res://icon.png  `u      �      G1?��z�c��vN��   res://icon.png.import   �Y      �      ��fe��6�B��^ U�   res://project.binaryP�      �      �|m<v�e~��`]̍   res://techdemo.gdnlib   P\      �       ��{���Q�Cu�    res://tests/TestingScene.tscn   �\      U      �ɭ|a��O��y�!`,   res://tests/scripts/TestingScene.gd.remap   �t      5       1�,[Y�,ĀC,��(�$   res://tests/scripts/TestingScene.gdcP^      �      (b8om��򬵚	4   res://tweening_library/scripts/CustomTween.gd.remap �t      ?       wZȲ+<��3V&�m0   res://tweening_library/scripts/CustomTween.gdc  Pe      �      E��V�W�ʯ�1=o0   res://tweening_library/scripts/Tweens.gd.remap   u      :       ��	��Z. %��C��N,   res://tweening_library/scripts/Tweens.gdc    q      4      +��a<{��=�ׅwk!            [gd_resource type="Environment" load_steps=2 format=2]

[sub_resource type="ProceduralSky" id=1]

[resource]
background_mode = 2
background_sky = SubResource( 1 )
             [gd_scene load_steps=2 format=2]

[ext_resource path="res://homework/sprites/playerShip1_blue.png" type="Texture" id=1]

[node name="Ship" type="Sprite"]
texture = ExtResource( 1 )
           [gd_resource type="NativeScript" load_steps=2 format=2]

[ext_resource path="res://techdemo.gdnlib" type="GDNativeLibrary" id=1]

[resource]
resource_name = "tweening"
class_name = "tweening"
library = ExtResource( 1 )
     [gd_scene load_steps=6 format=2]

[ext_resource path="res://homework/Ship.tscn" type="PackedScene" id=1]
[ext_resource path="res://homework/sprites/playerShip1_green.png" type="Texture" id=2]
[ext_resource path="res://homework/sprites/playerShip3_orange.png" type="Texture" id=3]
[ext_resource path="res://homework/sprites/enemyBlack1.png" type="Texture" id=4]
[ext_resource path="res://homework/Tweening.gdns" type="Script" id=5]

[node name="Tweening" type="Node2D"]
script = ExtResource( 5 )

[node name="Ship1" parent="." instance=ExtResource( 1 )]
position = Vector2( 160, 120 )

[node name="Ship2" parent="." instance=ExtResource( 1 )]
position = Vector2( 480, 120 )
texture = ExtResource( 2 )

[node name="Ship3" parent="." instance=ExtResource( 1 )]
position = Vector2( 160, 360 )
texture = ExtResource( 3 )

[node name="Ship4" parent="." instance=ExtResource( 1 )]
position = Vector2( 480, 360 )
texture = ExtResource( 4 )
            GDSC   !      6   �     ���ӄ�   �������Ӷ���   �����Ķ�   �����������򶶶�   ������������򶶶   ������������   �����϶�   ���������������򶶶�   ���������ƅ�   �����������󶶶�   ������������󶶶   �����¶�   ����¶��   ����������������Ҷ��   �����؇�   �����؄�   �����؅�   �����؂�   ������¶   �����Ŷ�   ����ض��   ���Ƈ���   ���Ƅ���   �������ض���   ���ƅ���   ���Ƃ���   ��������Ӷ��   ��������������ݶ   �����Ӷ�   �����ڶ�   �������ڶ���   �������Ӷ���   �������������������Ӷ���      Button1       Button2       Button3       Button4       Restart       modulate                             Button 1 pressed.         rotation   �        position   2         Button 2 pressed.      �         on_end_callback       Button 3 pressed.      d         Button 4 pressed.         Scene restarted.                               !      "      +      /   	   8   
   <      E      I      R      V      _      c      d      e      k      l      m      �      �      �      �      �      �      �           	     
        !     "   3  #   :  $   <  %   A  &   B  '   H  (   I  )   J  *   r  +   �  ,   �  -   �  .   �  /   �  0   �  1   �  2   �  3   �  4   �  5   �  6   3YY>�  N�  R�  R�  R�  R�  R�  R�  R�	  R�
  OYY0�  P�  QV�  �  &�  T�  PQV�  �  PQ�  &�  T�  P�  QV�  �  PQ�  &�  T�  P�  QV�  �  PQ�  &�  T�  P�  QV�  �  PQ�  &�  T�  P�  QV�  �  PQYYY0�  PQV�  �  �  �  T�  PW�  R�  R�  P�  R�  R�  R�  QR�  P�  R�  R�  R�  QR�  R�  T�  R�	  Q�  �?  P�
  Q�  Y0�  PQV�  �  �  T�  PW�  R�  R�  P�  R�  R�  R�  QR�  P�  R�  R�  R�  QR�  R�  T�  R�	  Q�  �  T�  PW�  R�  R�  R�  R�  R�  T�  R�	  Q�  �  T�  PW�  R�  RW�  T�  RW�  T�  �  P�  R�  QR�  R�  T�  R�	  Q�  �?  P�  Q�  Y0�  PQV�  �  �  T�  PW�  R�  RW�  T�  RW�  T�  �  P�  R�  QR�  R�  T�  R�  �8  PR�  Q�  Q�  �?  P�  Q�  Y0�  PQV�  �  �  �  T�  PW�  R�  RW�  T�  RW�  T�  �  P�  R�  QR�  R�  T�  R�	  QT�  P�  W�  T�  �  P�  R�  QQT�  P�  W�  T�  �  P�  R�  QQT�  P�  W�  T�  Q�  �?  P�  QYY0�  P�  QV�  �  T�  P�  T�  R�  R�  T�  R�  T�  R�  R�  T�  R�	  QYY0�  PQV�  �  PQT�   PQ�  �?  P�  QY`            GDST]   T            �	  WEBPRIFF�	  WEBPVP8L�	  /\�g��$GRd��=��+�~���n�F�$��b���.�\�<��v	rI���Z�ז�ߠ{+�Al[�r~�	$��`e�6��>@0ISm� ޟ�ftCՍV�A5C��*H�RuC��"DW U7��*�3B�T� 
*`��� I���M�$ ��6p������h�<�z��
(p��T�̥:ܨY&�*U�(�,� �j����ks���Q�c��̧�,��zF�̤&0�9���Pc�IJR�����WϨ�貵�{YZ�&� ������]:���|�a��t�-*��ߋ*�R�T�
tK�@*� �Zl� T�&��b#r+T+�e�D��Z7+~SV���0VW�=<_�{���r]����z���/R�փ�mI.������v�x2[����󉻻��"-l=���rA�24C�I�_;��ඍ IR7�pn�w�~D���O]�����x<)��NG��.�NSs�u=��!��S�D�j���#�W�3���'yD��[�s�+��㎂<9��P�\�u	��-����7�Ó���AL�M8ڃ��WGs"�,���^���#{��T^W����
��"bM�:I���O\�X><`���N�#I`���{�,c�' @�HD�j��t��4T �)�������x�	lȣ���N&���e刕:�9S/gZ]���n�>�.�;�5g��%3�����?zE�t
��\�@[�Y��$%�@�G�#2������'ēgA^��82����=O�A`���C�\(Q���G����'��<����;�d�Dft{)���ʗ�G����D��իF��ri�F�eI��c*����=�Y�R����e����He!�y��2+�T��J����MA�MjD�?��	G~JZp�c����E96�Q>e8Ze� �Hώ2!u1'n�qj�L�iA���K	ȋ2��[u��?���,�Lo�!�/JfT���7sU�3F�2��3�b��R���ו%c�e2a��R3�"�M�[F�C�_�0ƨ��L(x�e��k�+���?����ե�+�
��k}��HW�S_����dL�����Q�vq�Vf�,����5;ҙ�駟�5���'�bdb�V�+�h(��0�22g��?��l���b�,��������y��-Q??jN4R�C�|F,;b�>��͒qd{p���\9D{�Of�b��bR,+���1:ݥ�����~�3K�m��_���G�mc	�?�;����O�En(������N"1$N����m~�Dg�t�8�����IS���?�`�#-"��9�o_���s���-�����A��翐QB���$��H�(�m��;==A88x��'-������0� �b�頖K�
�b��E-�`A@�Xw����
�K�"��Z.Zź[�6�m#���5���T�V� T�.���0����<�'�q��c�݄r�P*�����ݨ񑿕I����!�b)Ƙy|���L}b��r��Ak��G���ϵ��Ļ��f?Sm��ˀ�b]�LeS��XKb�:W���T��m�
s����}�4����1���ڜP����v[ʥ`�XS�?�������O�b�]�r��*�N��(I�G�z�6Gis>(NЯc�rK�2]����%;FS��g�/��RJ������� P4������qt>���`��\����3�`8V4��#��䳿�%�`���V.S�:Ml(�j�]��,�G����	̅Bf�g����ŏ3�� �p��r���E^��e�,����r)+v��; c��[*Gs�[�e �Mtr~=#���� 1���Š*��Va�^G���^抝2�� +�b���s�Rg*��2�rer�<>Ἕ0�:K-ZFU�N#�Xe���T���M�����%�X���)�\��]s���`��$� �t*0`��\O�
�d��-��
'�L�'j�� ,�zJ�Z�	 �Y�tr(z���|m-��~��bʰ^����9N5l'���b������Z�e"ˊ��'�8���\�V����$q)ąuXM/W�[-_ZK�q\�R�u/�\YWl?@>V�BIG8� ���+����/�*�h4ʷ���+����D���֓�A�6�/��QP�9� �rEQ1 �
�#�H�q,�z����,����6\a�|�Br�"��B����H�� `;�\�Tl;@V�'��,($�+�����)�&	��\U����D@�� �&�+���)�Y����R�I�R�S'��!2���ǻi加b�ǹ�����i���9�p��P�l+v���y�ݡ/\���$�����8��ʕ-�p��]̈́���[W�޿%O�DG��޽'�{�P�X����@08�{����׮Jrl�     [remap]

importer="texture"
type="StreamTexture"
path="res://.import/enemyBlack1.png-0f9d8d722ff15e3c240393a28c6c5de8.stex"
metadata={
"vram_texture": false
}

[deps]

source_file="res://homework/sprites/enemyBlack1.png"
dest_files=[ "res://.import/enemyBlack1.png-0f9d8d722ff15e3c240393a28c6c5de8.stex" ]

[params]

compress/mode=0
compress/lossy_quality=0.7
compress/hdr_mode=0
compress/bptc_ldr=0
compress/normal_map=0
flags/repeat=0
flags/filter=true
flags/mipmaps=false
flags/anisotropic=false
flags/srgb=2
process/fix_alpha_border=true
process/premult_alpha=false
process/HDR_as_SRGB=false
process/invert_color=false
process/normal_map_invert_y=false
stream=false
size_limit=0
detect_3d=true
svg/scale=1.0
        GDSTc   K            �  WEBPRIFF�  WEBPVP8L�  /b�͐I۰���3�����F,��̟6E�$)� b�+��{(h#I��G	�_�K�dS �����p��-k�9��_��0T��l�,��a���\��xC+0�`v���lJ;��t�$C̽�۶U��m-�>�)b(�(��d���������N�e��o��=ff���p��|۶mڶ�m1��F�crym۶q����
�{�#݂m۶5f��"����mnXbQXA�A\�TE0��J6���m#IL�=2�xg��B  gǢ��^,Ր� �:#��(�H�` �%��A��{��(�b�y��)'�q ?�8BN��)4  �h�hF��-0�����X}�&�  ~���S8  #�Q�o>x�Gq�i�@�$  #�1:���|�  (�!@ D� �%PD��:�!�1<?x�4 �8����	��c��c�T��HձR�v��<hT/;u/ ��t���<$ B  ~����r@`��b� 1��
 ������|�p�@�
 ���nb ͨaѩ�{���/�ԁ���2yS�r�'�2N A �\$Ha t鱥 ���r� 4	� ��
  E �N��\L`��,B 
�\�r�  �������P  ������r1�:�E.�w�v��h( 'J� �����X�3[��1������^17�H���S��@���;���f�?���sds�X�j���	(�o���PH �9/	R(�B9.�6����� m �	��9= �����P�H���:J�#YF��>�lo��o  j<8mss��Χ�� � �i�����_������+}T���z���ݶ�;�;�o�� @� Ђ��q�' �	8�|:����]�lN���id��	� �H
�gL��Y�<a����ĒT�*��S9�  �����պ��ǻ���d�z���^���?�����  �i�V�n�RTv �X����{Q������U�)��d�z�|�P� \�[_y"p�1�"Rp=@�J}���("��ʜ�l ݗ8����1,e�Ce�L���Ij�Q9ټ�ӻ�z��E\G9��^%FI��d1ߗ�� uF�%D�#���� ��>�ק�R2*�J�7L�w>��,�L�Yz>�+<=���F#���z �UX�����ҨD� � �I	��0@�{>���Ё�H��jx�p�?��BqŪ� l8�ka�� ��מ�֛?m��@��l��;�/ �_"Y� �+ 0   ����#B�i�kI�������@qѯv����r�������!��)>U )�6=W���_^.���d&ÇS  `�^f� e�_�������`
W2& �wG ���&ꛟ������� @���a�����\�� غ�k�h�u�׷�� ђ�̊0{0,n/����T�jáɼ$����w��bvj�������ى�W  
倓�*1Hp� Y��G��D37�Ƕ���UӍM.&���?���^���@��h��_�����2��I1���3ɼ�v��C�.*������u�l�Hbxw���I��(�`�"%3��ZcI��\  `pe���f��=z��[�9WVS�'�  �l-��dƋhO:�.{5u˰W �����z4��&1X�:��HM@�; E ��+݊��"7����/� * �t��Xk���� �.  �	^>M7Vx�,�O�x��R�ԠQ�)��Ey �`4� �j�_>��M���e����
-/  ��u��̊+�X �/�wW ���(���� �5��W���`7Z� 0����|�mܶl����LT�� �����V��~k��?�lK��0uϰ�9ʽH�&p%�Ux.�  s_^�Ü :0 	|Vƒ����h�p���]_W�fo�[���'�_�?А�u0X�  ����j�KS)H���6g��׵*��	s��//�T6�~7��X���S������3.eyw|  �<���:Z�&2��p�W�AAb$,e,%��f;� ң�	��h��,�v擏f�(�(��S3m�|���`����t���-kU��� ����!l(�Zr<�����(7 ��`�kS�Xl��v�# 8��
//��K��O �?��G���`Of�=���d>���w* ���[�9�	�D��锎&`ӑ�"��绬tԀDw� (:�K+9T=�e�|dU����S�|���٢��P�������@��]�ʗMm�P�|�1]��d���0q��'���@�1�@�ݿ�?�&:�F"-ʦ:��`�I��B����~읃�ի��y��#����I�Ӆ�G��>8��z�(�4Dڙ~��(�I
a��e,��u��v������_�������9�F��(&� -���+V�j:��'_d�R�=N��dz�a�'S�.DZT�ũq�Ea�BK?Q�|�~L�}^o��  �n������,������?7��L�c��{���x0��P݇�[O��M�{��R��-[�1��s������ �$.�`/��n���e������lyP���哃�n���v�"q��錰mV� ���z��O�tZ~�=�J���~i��Thf>�t��˛w7����OG���W��S7�e��U7Eb9�6��{�@4��C�B�^oY���>��KGS��  U�?];6<�gL3K���4�r�=P7��0��Ε#��4VG.�[9��� p��T��mp�6����ڦ�����K'�����<���~	��@�Hv0��n��e �^����D0��^�qMf�Y �]tg���AS$fs�S��~�k+����Ҧ� ��w	\�
w �3@�������2�>QeG2QŌ�y�� �lb'3��8J�p��?΂Q\6��2���Yg
���:��R]jw]��pq��p
  vKQa6��) �D2 ��'��I{S&�_�y������9�h���S
�2S��Q\V���;���-��0y��Ę��k.��1��7��b�B`K��L������@r0�o��Dw �S  �xF'�Z�ؕ��;O(P���QnQt����1�a=�.sR���/�-�q4l�2��=f��~S��\4 �   �  �Mi>�N4�KcO���R�(�;g��˽Ο�iS9a��K�˽�����i�t��f!�� u2�H   .C
[�솖}Ac6��~w�y'�G�<��y�v(��KoR+x����r��7�.d���N���ۀ���M��O�& �j�ƭw� ��?
 P���`��[.��q�x��Wl&njA&nj��ؼE
���[.�����b]C�T�6��w����˽�����^����-+��r,`9�o��q�c��/��[/�����c����8�����
 ���Z���]��#� ��M��^��R���{R�M�g��&�
fp��o��o����n�C���@ �=wO�8o}���%��i�q��ƝL� K�� ��:��e�
�b��Ż���w��Gv�(`��+�>�zXf����q���;�rlXf�_ݐ�  h���y���/n��>6=\� � ��l_B�{P���n,��7w;           [remap]

importer="texture"
type="StreamTexture"
path="res://.import/playerShip1_blue.png-f0ced591f3114b0942d5fcc216ee32a9.stex"
metadata={
"vram_texture": false
}

[deps]

source_file="res://homework/sprites/playerShip1_blue.png"
dest_files=[ "res://.import/playerShip1_blue.png-f0ced591f3114b0942d5fcc216ee32a9.stex" ]

[params]

compress/mode=0
compress/lossy_quality=0.7
compress/hdr_mode=0
compress/bptc_ldr=0
compress/normal_map=0
flags/repeat=0
flags/filter=true
flags/mipmaps=false
flags/anisotropic=false
flags/srgb=2
process/fix_alpha_border=true
process/premult_alpha=false
process/HDR_as_SRGB=false
process/invert_color=false
process/normal_map_invert_y=false
stream=false
size_limit=0
detect_3d=true
svg/scale=1.0
         GDSTc   K            �  WEBPRIFF�  WEBPVP8L�  /b�͐I۰���3�����F ��O9�(fI�C���Y��P�H
4%� ���DB���7t���<yxӶ=�ckێK��@k�J�33�d�`�I=Y�V����3s��+��a[�f�C
x���m��6ڶ��q]�Y%������FS��q�\M��1&I�y��m۴m[�b)��>�\�m۶ye{��l۶}k��^���V[�P[{�6�,1��� X� .�y�"��`��A%
���@��F�$ə]5=Q�#�� o�<�h  ��Y4s��Q-  |�7�  �"�8���p�_��	|q�ER/зTD0	gCTDh�B#��F�E3j��FP ���b�8C #�}��xF��.�罗�a�� �~U�2�l? �8�~@ �=� !�	�@J��F! ��������@�	��UVL`�.��B;G��U����A#�ثg�$P T�O�
 !���9 ��E1�C�� �@�$�=��7� �ăD�QáW��94#�p�u��O�!����&No ���O)9��o�(0�%X `ѧ�-�ē X( M�/ 4��B@����^B�ù7/B 
�, DЗ�l��<���g�`1��(�>�}��x}��d �TGU  �������۲������f0�"�_S Xd �b���n5r�ѭp�\ wNl�(j�ܢ�틽f0�( �[,�ұ(0�"(4�cq����ΰ=@k �=�b x�׮�y_@�����_$R�?)�mH��>^l%�V�����_s���4q#@�  ��,8���%��>~�[�K8+yT��;�W;m~���Wf  ��  Z�����y�V�w	�(�d�������Y۞[�9�֐�(,,��q8���q�;/ ђʨ�?85�+  ���o��������W_���.?ٺ��g����� ���_$ �H���hEU��� G�p|�6)�Gޗ��ĳb�1��y���	C��t��|��4Q+�MdL���&��0�U�v��V �=�0m]r�Gf;TU�i:� 8M��n_ۺݛgvo�I����JdE���� ��J�,<LW���*����E ���T}Ô�q��/�.`�]&�z5�������g��dL��  ��hey5Z�`@��
 n��;@��|f=�A��[8��P��Ϊ� `3[�;P�p����]�;� =L�r �C��/�YU0��
 �  ` @u�����m�����v�I�Cj*P|�k���q�~t��_ Tt�i�Z��l\��z @��]M�f��؟'S=ÇK  ���	(�;����U�f��U�  �dy�]�86���	� ���*�Q��j�]e���Q��G�36  ��SUL�YW�7�6��(�16*�j3]B�$_����%5�4A�̞?�_&  ��f�IO�*�(�bN �8e���#�����M������+:��d��`#J����� ����ha�����p���������e%�-�Tv�R9�K��˰t�g�.�mX��D��")� E�t��Ҳ ��#� ������p��m���ww�p�w���A�WӘ�*<����V;��� �]c���A�&�zK��/��R B�v����
���s���m'�5 8AE  >}Ƣ*�����8�J@�  Hm�葝tm�Y����J��f�.oUu�� � i�d��4 �[X�ܞ�O�^�ٖ
��   ~��E���  �`�/��pcm�I����k%fb���I��D��  ��ۮ�,����~V/�G��� �z�,n���]������!c{�12�p65�����
cM@�m `ۂ������m :� �T&��5���(�p���}�WU����l�����:�Y�  �����3�r�*���Lj��]k�R�Bqʳ���;��#n3��Vx�<T�^��?��p�����@��Q�e;Ɯ��Y�N���g�hI˕�+�8�q� �����~R+�t|�CR�J�
O�'Y�=[a�5���3��pʘ�D���\��%49ŵ�@���Z�|<�B��I�8��2�e�Zl��)"�IW[J��8f	 ǻ��xa_I?����[�>��h��-+�q� `��53_�� �I>� ����ww�������Rs��CO�Tjg�8�
� �3�gl�  �f���kR�Ju�� �g	3�kg� >��(.����������0�f8]��k���5. ;�ف�̻��,��S	:QJb�T����������y�ܐ�bS�,:��`[�j���yv~�ś;�ǵ%'>5�v��x �w��vvi�X�����9L���(��Y�`�Z��;�GL���g��M��V��ɭ$&Htf~/F6��[�C}����I���P���=��<��;L�y�,F1cq83�PEpE-X��������F���|z ��D�}�bEb�g��Gl�+��|5Z��靪�__���:����ݰy0���lw3g��<�<s���O��읹 ��E	��d���χ��qi�9ݑ�̿8Gu�0[#�9#\n3sդ�9�m ��o��|�������_�J�/-��,��I��Zr��/zqnS���ډ��/��	�GO�^U���u##�T��E�}a�9
��C�q�Z^�����h���|}�0�N<pf@��� .<�o�$�,���,����M;+bɤ%�](Ck�j��Zퟹ�d����,15�;�����-u&�3�s*�G;���57�HE��纋4�5 �X�ǲϓJ"LƢs�>�A��4W�  ;Y�^�>�)S����!�V��Sik0���*j.�� ���O� ��fk>�~��"RUL�����  �(3��'屬�lf���8�tk*�������:
NvBw�]��:{�w��L4�B��(Z-���t�z�T |�C��j
J4U����?6�$9[s�|?Q��bJaT*�f����ѿ߶��L.�>���؎�)G'(�����b�N"p�d,������1��>b��`:  ��iV(�Y��'�)J��l�G!BT*�r��`�w��MN��Y�~K*p%^+Q  ���[��c:R:F�G���   e�.  pPPE����FV�'�E�ddU��-fW��^��*�8PÚ��c�㍍�W*7�Xw�-�Ω�JDp��8�-I   ��$-�B��Bgw���_�ۯ~����D�+3��.��<X|�i��s�|�
*�_h���y�m���	���[�m �6 o��- ����M�o%Y���,�c��<q���v���3x�</1���������(U�2N��N���+]��".��y ���=�E1��^�˳�TXz�bI���X� �"��cM��~P�6�7_}p���b� ���1}a7s�-�ܽG�����ppT� �=mΧ�+����& �F���K�^,��ִ��ŎqP3ר�GNm��k �����;2x�5-={��{kz�ȰP|�'1�/�Vc��m��n"L]����G�A�_�/�*�ma��+TX~�Z�_�V�W ��� �Տ, �fY�&�f{��K����t����f���� ����MtGO�8:,
  `pW  [remap]

importer="texture"
type="StreamTexture"
path="res://.import/playerShip1_green.png-4ec31ecb47dff1e1c73f710296640692.stex"
metadata={
"vram_texture": false
}

[deps]

source_file="res://homework/sprites/playerShip1_green.png"
dest_files=[ "res://.import/playerShip1_green.png-4ec31ecb47dff1e1c73f710296640692.stex" ]

[params]

compress/mode=0
compress/lossy_quality=0.7
compress/hdr_mode=0
compress/bptc_ldr=0
compress/normal_map=0
flags/repeat=0
flags/filter=true
flags/mipmaps=false
flags/anisotropic=false
flags/srgb=2
process/fix_alpha_border=true
process/premult_alpha=false
process/HDR_as_SRGB=false
process/invert_color=false
process/normal_map_invert_y=false
stream=false
size_limit=0
detect_3d=true
svg/scale=1.0
      GDSTb   K            �  WEBPRIFF�  WEBPVP8L�  /a��9�mU�>w��Ʉ \F�n�δC�I�b���1������R�io��ƶ���牙r�
ոZQff���9im���3X!����J!����!�,��oW+s�_-0P�	'��� jAX(�h	5@���N8�� ~�0@�q��HIg*Z1���K���Q�w��K�F��4{�S_x�qY���+�2u4"~��|��Ƚʽ2(S�{岆����/r��z��_�߸;a�f � @J	C�㩨�O ��j�=4�iaH�"C3H�	4H�C����L4�J�D�	5���0L�CI0$ ��}�K}8;����S�6�=�XS�-F5���&}U����)ൾ�x�_c�A�~�<����j�����gb���<a���64�X��N�U1X>�:��~�-�}>M�]Z��Z�_1nS��k�����E'�A3Y�<���Y�љar"��g�:3tk�W[��'_g*ZQBlCX���l^�oX��O��xm�_wa&��Y(�;�3���.!��w���pw/$�����w�d/炻;����U�LD�!�m$I��p�%=k<�$&�S�T:=f ��?�Ii�ĥ8I9��.B��H�S�.vl"&��@��pi�M�
�<VG:]��a����C�X�|��d%���je�lL1��XY�;�`��hp	CX?HR�+�ȓ���F�j���!����뺎3�j7�Z��-.���H`�]	��bC�Ϙ+
|����pv,T"րR�B�4^���C�͈��RjF,�ߞ�y^���Y�ׇ��L��Wg�N�k�/G楗�h����%I����m.q>[`{tf�����!�k�$�>e�������l~�&�L\N��X}w�)��y��-��Y��\��r���[ 6�ƧM"�-(\!e1�������\ס�=��§S/�
�B��f�����'�=�9��G�{�F>��@,XHf�4~�XP��:��B�f����\bobA^[@g:�E� u�gg2�� ��q>���.��tf�k ��
��+vq���&N���cg�Gf��!!�!{�8���N>e�v�}��[0��G�x� �O�ظ���Oޮ�������'��{R���~����d=�bɭ|Fw�}�	d&O��/B��$&��9� �U�����Ȩ»��� P�xz�ε��>!��%<�>���L~k��>E�ed�A,��*�c�>?�B:��M�:7�� .��~�~���'�THf.�i�\)�أ�B�	�J�vPZ'�SR�çN"�����g�K���@ьxq 㓈��=B�U��V�G��~fm�R��P$�$s.b��%���W=N��E-\HF�~�$����e��
�U���T}��#����B#�Z��Џ�U�ڗ�ȐB��${X��m�A���D�˓�gvIz���Ӣ9�<y��/��Z�x�8TP�$ =Yb�T����f����<}]�Z�C���d=� }�9/��߭>,���f�{�6���/u���Rh�F0���~3�3�����Cg�]Zr�5X	�d�0��C�ydH��ơ�R�F3a�%���/�����
[� �E$A�5��w��B��%����P�{��R9�!���3KY��ܣ��x�9cn
ї˒�4�? �4�D����}y���х�|-��r�'����ljB�#�_�a�ѩ��G��Z�lv�*��f0���>a����5�K�5Q)�,{��d-��n�S�O�����Y�m^NҲǰ��I���>j�qș}LZx�r����r��Ki{|:q�U3i�_�:�4��R�X�<��h+\g���Ƞ�m�IXk���̡�i�X��7(׀Ai2�`GP��J�ӎ;�u��&P	3�ņ~l��P�Y����'�-@":u`a�b������ɚ �M����������6v��A�@� �L{T��LZ�P�ɺ��?�����?�TE��⿽���~l(��!�?}g׷_~��׿C�Ѩ4��W_}�M�W�} �.ʔG�%���! �"H��駟��$��������?[��������:��{��~o�F��U�ǆ`D����z��S�Z��٩!�����F4�k�@����K�^�'�L����vSћ�����ˎ�K9�l�l=ǖ�d��@稲XZ%��k�l�Ģ Jvbsx�3q��A.��%    [remap]

importer="texture"
type="StreamTexture"
path="res://.import/playerShip3_orange.png-8962c97ec7ba19d91ab25996dd16b951.stex"
metadata={
"vram_texture": false
}

[deps]

source_file="res://homework/sprites/playerShip3_orange.png"
dest_files=[ "res://.import/playerShip3_orange.png-8962c97ec7ba19d91ab25996dd16b951.stex" ]

[params]

compress/mode=0
compress/lossy_quality=0.7
compress/hdr_mode=0
compress/bptc_ldr=0
compress/normal_map=0
flags/repeat=0
flags/filter=true
flags/mipmaps=false
flags/anisotropic=false
flags/srgb=2
process/fix_alpha_border=true
process/premult_alpha=false
process/HDR_as_SRGB=false
process/invert_color=false
process/normal_map_invert_y=false
stream=false
size_limit=0
detect_3d=true
svg/scale=1.0
   GDST@   @            �  WEBPRIFF�  WEBPVP8L�  /?����m��������_"�0@��^�"�v��s�}� �W��<f��Yn#I������wO���M`ҋ���N��m:�
��{-�4b7DԧQ��A �B�P��*B��v��
Q�-����^R�D���!(����T�B�*�*���%E["��M�\͆B�@�U$R�l)���{�B���@%P����g*Ųs�TP��a��dD
�6�9�UR�s����1ʲ�X�!�Ha�ߛ�$��N����i�a΁}c Rm��1��Q�c���fdB�5������J˚>>���s1��}����>����Y��?�TEDױ���s���\�T���4D����]ׯ�(aD��Ѓ!�a'\�G(��$+c$�|'�>����/B��c�v��_oH���9(l�fH������8��vV�m�^�|�m۶m�����q���k2�='���:_>��������á����-wӷU�x�˹�fa���������ӭ�M���SƷ7������|��v��v���m�d���ŝ,��L��Y��ݛ�X�\֣� ���{�#3���
�6������t`�
��t�4O��ǎ%����u[B�����O̲H��o߾��$���f���� �H��\��� �kߡ}�~$�f���N\�[�=�'��Nr:a���si����(9Lΰ���=����q-��W��LL%ɩ	��V����R)�=jM����d`�ԙHT�c���'ʦI��DD�R��C׶�&����|t Sw�|WV&�^��bt5WW,v�Ş�qf���+���Jf�t�s�-BG�t�"&�Ɗ����׵�Ջ�KL�2)gD� ���� NEƋ�R;k?.{L�$�y���{'��`��ٟ��i��{z�5��i������c���Z^�
h�+U�mC��b��J��uE�c�����h��}{�����i�'�9r�����ߨ򅿿��hR�Mt�Rb���C�DI��iZ�6i"�DN�3���J�zڷ#oL����Q �W��D@!'��;�� D*�K�J�%"�0�����pZԉO�A��b%�l�#��$A�W�A�*^i�$�%a��rvU5A�ɺ�'a<��&�DQ��r6ƈZC_B)�N�N(�����(z��y�&H�ض^��1Z4*,RQjԫ׶c����yq��4���?�R�����0�6f2Il9j��ZK�4���է�0؍è�ӈ�Uq�3�=[vQ�d$���±eϘA�����R�^��=%:�G�v��)�ǖ/��RcO���z .�ߺ��S&Q����o,X�`�����|��s�<3Z��lns'���vw���Y��>V����G�nuk:��5�U.�v��|����W���Z���4�@U3U�������|�r�?;�
         [remap]

importer="texture"
type="StreamTexture"
path="res://.import/icon.png-487276ed1e3a0c39cad0279d744ee560.stex"
metadata={
"vram_texture": false
}

[deps]

source_file="res://icon.png"
dest_files=[ "res://.import/icon.png-487276ed1e3a0c39cad0279d744ee560.stex" ]

[params]

compress/mode=0
compress/lossy_quality=0.7
compress/hdr_mode=0
compress/bptc_ldr=0
compress/normal_map=0
flags/repeat=0
flags/filter=true
flags/mipmaps=false
flags/anisotropic=false
flags/srgb=2
process/fix_alpha_border=true
process/premult_alpha=false
process/HDR_as_SRGB=false
process/invert_color=false
process/normal_map_invert_y=false
stream=false
size_limit=0
detect_3d=true
svg/scale=1.0
              [entry]

Windows.64="res://TechDEMOcpp.dll"

[dependencies]

Windows.64=[  ]

[general]

singleton=false
load_once=true
symbol_prefix="godot_"
reloadable=true
 [gd_scene load_steps=3 format=2]

[ext_resource path="res://tests/scripts/TestingScene.gd" type="Script" id=1]
[ext_resource path="res://icon.png" type="Texture" id=2]

[node name="TestingScene" type="Node2D"]
script = ExtResource( 1 )

[node name="Sprite" type="Sprite" parent="."]
position = Vector2( 320, 240 )
texture = ExtResource( 2 )
           GDSC         G   �      ���ӄ�   �������Ӷ���   �����Ķ�   �����������򶶶�   ������������򶶶   ������������   �����϶�   ���������������򶶶�   ���������ƅ�   �����������󶶶�   ������������󶶶   �����¶�   ����¶��   ����������������Ҷ��   �����؇�   ������¶   �����Ŷ�   ����ض��   �����Ӷ�   ��������Ӷ��   �������Ӷ���   �������������������Ӷ���   ��������������ݶ   ����������ض   ������¶   ������������Ӷ��   �������������Ӷ�      Button1       Restart       Button 1 pressed.         position   @     �      �     d                �     h        Scene restarted.                                            !      "      +      /   	   8   
   <      =      >      D      E      J      K      L      M      N      O      P      Q      R      S      T      U      V      W      X      Y      Z       [   !   \   "   ]   #   ^   $   _   %   `   &   a   '   b   (   c   )   d   *   e   +   f   ,   g   -   h   .   i   /   j   0   k   1   l   2   m   3   n   4   o   5   p   6   q   7   r   8   s   9   t   :   �   ;   �   <   �   =   �   >   �   ?   �   @   �   A   �   B   �   C   �   D   �   E   �   F   �   G   3YY>�  N�  R�  R�  R�  R�  R�  R�  R�	  R�
  OYY0�  P�  QV�  �  &�  T�  PQV�  �  PQ�  &�  T�  P�  QV�  �  PQYYY0�  PQV�  �  �?  P�  Q�  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  T�  PW�  R�  R�  P�  R�  QR�  P�  R�  QR�  R�  T�	  R�	  QT�  P�  P�
  R�  QQYYYY0�  PQV�  �  PQT�  PQ�  �?  P�  Q�  �  YY0�  P�  V�  QV�  �  T�  P�  T�  R�  R�  T�  R�  T�  R�  R�  R�	  Q�  Y`            GDSC   *      R   �     ���Ӷ���   ����������ض   ¶��   ζ��   �������ڶ���   �����ڶ�   �������������Ŷ�   ����ζ��   �������ض���   �����Ӷ�   ��������Ķ��   ��������ն��   ������Ҷ   ��������Ŷ��   ���¶���   �����Ķ�   �����϶�   �����������󶶶�   ������������󶶶   �����������򶶶�   ������������򶶶   �����������󶶶�   ������������󶶶   ������������   ���������ƅ�   ���������������򶶶�   ����¶��   ���߶���   �����Ӷ�   ����۶��   ����¶��   ��Ҷ   ��Ķ   �����Ѷ�   �����ж�   �����Ҷ�   �����Ӷ�   ����׶��   ��¶   ���ڶ���   ��������Ӷ��   ������Ӷ             linear              EASE_IN_QUAD            EASE_OUT_QUAD               SmoothStepN             Bouncy              EASE_IN_OUT_QUAD            SmoothStep3             EASE_IN_SINE            EASE_OUT_SINE         ?                �?                                     	               	      
         !      &      )      ,      /      2      5      :      ;      d      e      k      v      |      �      �      �      �      �      �      �       �   !   �   "     #   "  $   (  %   7  &   =  '   T  (   Z  )   k  *   q  +   y  ,   �  -   �  .   �  /   �  0   �  1   �  2   �  3   �  4   �  5   �  6   �  7   �  8     9     :     ;     <     =   $  >   %  ?   .  @   4  A   :  B   >  C   K  D   O  E   V  F   _  G   g  H   n  I   }  J   ~  K   �  L   �  M   �  N   �  O   �  P   �  Q   �  R   3YYY2�  YYY;�  V�  Y;�  V�  Y;�  Y;�  Y;�  V�  LMY;�  V�  Y;�  Y;�	  Y;�
  Y;�  Y;�  Y;�  V�  YY;�  NV�  R�  V�  R�  V�  R�  V�  R�  V�	  R�
  V�  R�  V�  R�  V�  R�  V�  OYY0�  PQV�  .�  �  P�  �  QY0�  PQV�  .P�  �  QP�  �  Q�  �  �  �  Y0�  PQV�  .�  P�  �  PP�  ZQ�  QQP�  �  QY0�  PQV�  .�  PPP�  ZQ�  QQP�  �  QY0�  PQV�  .�  P�  P�  �  QP�  �  QQP�  �  QY0�  PQV�  .�  �  �  P�  �  QY0�  PQV�  .�  P�  P�  �  QP�  �  QP�  �  QQP�  �  QY0�  PQV�  .�  �  �  �  P�  �  QY0�  PQV�  .�  PP�  �  Q�  �  P�  �  �  QQY0�  PQV�  .�  �  PQP�  �  Q�  PQY0�  PQV�  &P�  	�  QV�  .�  �  �  �  P�  �  Q�  (V�  .�  P�  P�  �  �  QP�  �  �  Q�  QP�  �  QYYY0�  P�  V�  R�  V�  R�  R�  �  R�   �  R�!  V�  R�"  �  QV�  T�	  �  �  T�  T�#  P�  Q�  T�  T�#  P�  Q�  T�  �  �  T�  �  �  T�  �   �  T�
  �  �  T�  �!  �  T�  �  �  T�  �  �  T�  �"  �  T�  �X  P�  Q�  YY0�$  P�%  V�  QV�  �  �%  �  �  &�  �  V�  �  �  �  '�  �  P�  �  Q�  V�  �  �  �  �  �  L�  M�  �  �  L�  �  M�  �  �  �  �  �  &�Y  P�	  QV�  �	  T�&  P�
  R�'  P�  L�  MQQYY0�(  P�  QV�  �  T�#  P�  Q�  �  �  �  .YY0�)  PQX�  V�  .�  �  Y`              GDSC            �      ���Ӷ���   �����Ŷ�   �������Ŷ���   ����׶��   ߶��   ����ض��   �����Ӷ�   ������Ӷ   �����¶�   ������Ҷ   ��������ն��   �����Ӷ�   ����۶��   �������ڶ���   �����ڶ�   ��Ķ   ��������ն��   ����������ض   ����   �����Ҷ�                                                                     	   #   
   +      2      :      A      I      R      U      Y      Z      [      n      �      �      �      3YYY;�  V�  LMYY0�  P�  QV�  ;�  �  �  *�  	�X  P�  QV�  ;�  �  L�  M�  �  T�  P�  Q�  &�  T�  PQV�  �  T�  P�  Q�  &�  T�	  �  V�  �  T�	  T�
  P�  Q�  (V�  �  �  YYY0�  P�  R�  R�  R�  R�  R�  R�	  QV�  ;�  �  T�  P�  R�  R�  R�  R�  R�  R�	  Q�  �  T�  P�  Q�  .�  Y`            [remap]

path="res://homework/scripts/Tweening.gdc"
            [remap]

path="res://tests/scripts/TestingScene.gdc"
           [remap]

path="res://tweening_library/scripts/CustomTween.gdc"
 [remap]

path="res://tweening_library/scripts/Tweens.gdc"
      �PNG

   IHDR   @   @   �iq�   sRGB ���  �IDATx��ytTU��?�ի%���@ȞY1JZ �iA�i�[P��e��c;�.`Ow+4�>�(}z�EF�Dm�:�h��IHHB�BR!{%�Zߛ?��	U�T�
���:��]~�������-�	Ì�{q*�h$e-
�)��'�d�b(��.�B�6��J�ĩ=;���Cv�j��E~Z��+��CQ�AA�����;�.�	�^P	���ARkUjQ�b�,#;�8�6��P~,� �0�h%*QzE� �"��T��
�=1p:lX�Pd�Y���(:g����kZx ��A���띊3G�Di� !�6����A҆ @�$JkD�$��/�nYE��< Q���<]V�5O!���>2<��f��8�I��8��f:a�|+�/�l9�DEp�-�t]9)C�o��M~�k��tw�r������w��|r�Ξ�	�S�)^� ��c�eg$�vE17ϟ�(�|���Ѧ*����
����^���uD�̴D����h�����R��O�bv�Y����j^�SN֝
������PP���������Y>����&�P��.3+�$��ݷ�����{n����_5c�99�fbסF&�k�mv���bN�T���F���A�9�
(.�'*"��[��c�{ԛmNު8���3�~V� az
�沵�f�sD��&+[���ke3o>r��������T�]����* ���f�~nX�Ȉ���w+�G���F�,U�� D�Դ0赍�!�B�q�c�(
ܱ��f�yT�:��1�� +����C|��-�T��D�M��\|�K�j��<yJ, ����n��1.FZ�d$I0݀8]��Jn_� ���j~����ցV���������1@M�)`F�BM����^x�>
����`��I�˿��wΛ	����W[�����v��E�����u��~��{R�(����3���������y����C��!��nHe�T�Z�����K�P`ǁF´�nH啝���=>id,�>�GW-糓F������m<P8�{o[D����w�Q��=N}�!+�����-�<{[���������w�u�L�����4�����Uc�s��F�륟��c�g�u�s��N��lu���}ן($D��ת8m�Q�V	l�;��(��ڌ���k�
s\��JDIͦOzp��مh����T���IDI���W�Iǧ�X���g��O��a�\:���>����g���%|����i)	�v��]u.�^�:Gk��i)	>��T@k{'	=�������@a�$zZ�;}�󩀒��T�6�Xq&1aWO�,&L�cřT�4P���g[�
p�2��~;� ��Ҭ�29�xri� ��?��)��_��@s[��^�ܴhnɝ4&'
��NanZ4��^Js[ǘ��2���x?Oܷ�$��3�$r����Q��1@�����~��Y�Qܑ�Hjl(}�v�4vSr�iT�1���f������(���A�ᥕ�$� X,�3'�0s����×ƺk~2~'�[�ё�&F�8{2O�y�n�-`^/FPB�?.�N�AO]]�� �n]β[�SR�kN%;>�k��5������]8������=p����Ցh������`}�
�J�8-��ʺ����� �fl˫[8�?E9q�2&������p��<�r�8x� [^݂��2�X��z�V+7N����V@j�A����hl��/+/'5�3�?;9
�(�Ef'Gyҍ���̣�h4RSS� ����������j�Z��jI��x��dE-y�a�X�/�����:��� +k�� �"˖/���+`��],[��UVV4u��P �˻�AA`��)*ZB\\��9lܸ�]{N��礑]6�Hnnqqq-a��Qxy�7�`=8A�Sm&�Q�����u�0hsPz����yJt�[�>�/ޫ�il�����.��ǳ���9��
_
��<s���wT�S������;F����-{k�����T�Z^���z�!t�۰؝^�^*���؝c
���;��7]h^
��PA��+@��gA*+�K��ˌ�)S�1��(Ե��ǯ�h����õ�M�`��p�cC�T")�z�j�w��V��@��D��N�^M\����m�zY��C�Ҙ�I����N�Ϭ��{�9�)����o���C���h�����ʆ.��׏(�ҫ���@�Tf%yZt���wg�4s�]f�q뗣�ǆi�l�⵲3t��I���O��v;Z�g��l��l��kAJѩU^wj�(��������{���)�9�T���KrE�V!�D���aw���x[�I��tZ�0Y �%E�͹���n�G�P�"5FӨ��M�K�!>R���$�.x����h=gϝ�K&@-F��=}�=�����5���s �CFwa���8��u?_����D#���x:R!5&��_�]���*�O��;�)Ȉ�@�g�����ou�Q�v���J�G�6�P�������7��-���	պ^#�C�S��[]3��1���IY��.Ȉ!6\K�:��?9�Ev��S]�l;��?/� ��5�p�X��f�1�;5�S�ye��Ƅ���,Da�>�� O.�AJL(���pL�C5ij޿hBƾ���ڎ�)s��9$D�p���I��e�,ə�+;?�t��v�p�-��&����	V���x���yuo-G&8->�xt�t������Rv��Y�4ZnT�4P]�HA�4�a�T�ǅ1`u\�,���hZ����S������o翿���{�릨ZRq��Y��fat�[����[z9��4�U�V��Anb$Kg������]������8�M0(WeU�H�\n_��¹�C�F�F�}����8d�N��.��]���u�,%Z�F-���E�'����q�L�\������=H�W'�L{�BP0Z���Y�̞���DE��I�N7���c��S���7�Xm�/`�	�+`����X_��KI��^��F\�aD�����~�+M����ㅤ��	SY��/�.�`���:�9Q�c �38K�j�0Y�D�8����W;ܲ�pTt��6P,� Nǵ��Æ�:(���&�N�/ X��i%�?�_P	�n�F�.^�G�E���鬫>?���"@v�2���A~�aԹ_[P, n��N������_rƢ��    IEND�B`�       ECFG      _global_script_classes�                     class         CustomTween       language      GDScript      path   -   res://tweening_library/scripts/CustomTween.gd         base      Node   _global_script_class_icons$               CustomTween           application/config/name         3-2-TweeningLibrary    application/run/main_scene$         res://homework/Tweening.tscn   application/config/icon         res://icon.png     autoload/Tweens4      )   *res://tweening_library/scripts/Tweens.gd      display/window/size/width      �     display/window/size/height      �     input/Button1�              deadzone      ?      events              InputEventKey         resource_local_to_scene           resource_name             device            alt           shift             control           meta          command           pressed           scancode          physical_scancode      1      unicode           echo          script         input/Button2�              deadzone      ?      events              InputEventKey         resource_local_to_scene           resource_name             device            alt           shift             control           meta          command           pressed           scancode          physical_scancode      2      unicode           echo          script         input/Button3�              deadzone      ?      events              InputEventKey         resource_local_to_scene           resource_name             device            alt           shift             control           meta          command           pressed           scancode          physical_scancode      3      unicode           echo          script         input/Button4�              deadzone      ?      events              InputEventKey         resource_local_to_scene           resource_name             device            alt           shift             control           meta          command           pressed           scancode          physical_scancode      4      unicode           echo          script         input/Restart�              deadzone      ?      events              InputEventKey         resource_local_to_scene           resource_name             device            alt           shift             control           meta          command           pressed           scancode          physical_scancode      R      unicode           echo          script         mono/project/assembly_name         3-2-TweeningLibrary )   physics/common/enable_pause_aware_picking         $   rendering/quality/driver/driver_name         GLES2   %   rendering/vram_compression/import_etc         &   rendering/vram_compression/import_etc2          )   rendering/environment/default_environment          res://default_env.tres        