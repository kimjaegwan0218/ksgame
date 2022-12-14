using UnityEngine;
using System.Collections;

public class CameraController : MonoBehaviour {

    // 플레이어 게임 개체에 대한 공개 참조를 저장하여 변환을 참조할 수 있습니다.
    public GameObject player;

    // 플레이어에서 Vector3 오프셋을 저장합니다(항상 플레이어에서 카메라를 배치할 거리).
    private Vector3 offset;

    // 게임 초반
    void Start ()
	{
        // 플레이어의 위치에서 카메라의 위치를 ​​빼 오프셋을 만듭니다.
        offset = transform.position - player.transform.position;
	}

    // 표준 'Update()' 루프 실행 후, 그리고 각 프레임이 렌더링되기 직전
    void LateUpdate ()
	{
        // 카메라(이 스크립트가 연결된 게임 개체)의 위치를 ​​설정합니다.
        // 플레이어의 위치에 오프셋 금액을 더한 값
        transform.position = player.transform.position + offset;
	}
}