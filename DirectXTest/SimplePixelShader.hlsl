struct PixelShaderInput
{
	float color : COLOR;
};

float4 SimplePixelShader(PixelShaderInput IN) : SV_TARGET
{
	return IN.color;
}