using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;
public class Exit : MonoBehaviour
{
    public void GameEndBtnClick()
    {
#if UNITY_EDITOR
        UnityEditor.EditorApplication.isPlaying = false;
#else
        Application.Quit(); // �� �Լ��� ����Ƽ���� ������� �ʱ⶧���� ���� �Բ� �Ѵ�.
#endif
    }
}
